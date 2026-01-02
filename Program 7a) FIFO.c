#include <stdio.h>

int main() {
    int n, pages[50], frames[10];
    int nof, i, j, k, front = 0, faults = 0, hit;

    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    printf("\nENTER THE PAGE NUMBER :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("\nENTER THE NUMBER OF FRAMES : ");
    scanf("%d", &nof);

    for (i = 0; i < nof; i++)
        frames[i] = -1;

    printf("\nref string\tpage frames\n");
    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < nof; j++)
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }

        if (!hit) {                     // page fault
            frames[front] = pages[i];   // replace oldest page
            front = (front + 1) % nof;
            faults++;
        }

        printf("%d\t\t", pages[i]);
        for (k = 0; k < nof; k++)
            printf("%d\t", frames[k]);
        printf("\n");
    }

    printf("\nPage Fault Is %d\n", faults);
    return 0;
}
