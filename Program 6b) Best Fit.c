#include <stdio.h>

int main() {
    int nb, np, i, j;
    int b[20], p[20], block[20] = {0}, alloc[20] = {0}, frag[20];

    printf("\nMemory Management Scheme - Best Fit");
    printf("\nEnter the number of blocks:");  scanf("%d", &nb);
    printf("Enter the number of processes:"); scanf("%d", &np);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no.%d:", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no.%d:", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= np; i++) {
        int best = -1, bestFrag = 100000;
        for (j = 1; j <= nb; j++)
            if (!block[j] && b[j] >= p[i] && b[j] - p[i] < bestFrag) {
                bestFrag = b[j] - p[i];
                best = j;
            }
        if (best != -1) {
            alloc[i] = best;
            frag[i] = bestFrag;
            block[best] = 1;
        }
    }

    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np && alloc[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
               i, p[i], alloc[i], b[alloc[i]], frag[i]);

    return 0;
}
