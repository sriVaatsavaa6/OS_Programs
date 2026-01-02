#include <stdio.h>
#define MAX 25

int main() {
    int nb, nf, i, j;
    int b[MAX], f[MAX], used[MAX] = {0}, alloc[MAX] = {0}, frag[MAX];

    printf("\nMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");  scanf("%d", &nb);
    printf("Enter the number of files: ");    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++)
            if (!used[j] && b[j] >= f[i]) {
                alloc[i] = j;
                frag[i]  = b[j] - f[i];
                used[j]  = 1;
                break;
            }
        if (!alloc[i]) frag[i] = 0;      // not allocated
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
               i, f[i],
               alloc[i],
               alloc[i] ? b[alloc[i]] : 0,
               frag[i]);

    return 0;
}
