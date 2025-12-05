#include <stdio.h>

int main() {
    int Max[10][10], Alloc[10][10], Need[10][10];
    int Avail[10], Completed[10], Safe[10];
    int p, r, i, j, count = 0, proc;

    printf("Enter the no of processes : ");
    scanf("%d", &p);

    printf("Enter the no of resources : ");
    scanf("%d", &r);

    for (i = 0; i < p; i++)
        Completed[i] = 0;

    printf("\nEnter the Max Matrix for each process : ");
    for (i = 0; i < p; i++) {
        printf("\nFor process %d : ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }

    printf("\nEnter the allocation for each process : ");
    for (i = 0; i < p; i++) {
        printf("\nFor process %d : ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Alloc[i][j]);
    }

    printf("\nEnter the Available Resources : ");
    for (i = 0; i < r; i++)
        scanf("%d", &Avail[i]);

    // Need = Max - Alloc
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];

    do {
        printf("\nMax matrix:\tAllocation matrix:\n");
        for (i = 0; i < p; i++) {
            for (j = 0; j < r; j++)
                printf("%d ", Max[i][j]);
            printf("\t\t");
            for (j = 0; j < r; j++)
                printf("%d ", Alloc[i][j]);
            printf("\n");
        }

        proc = -1;

        // find one process whose Need <= Avail and not yet completed
        for (i = 0; i < p; i++) {
            if (Completed[i] == 0) {
                int canRun = 1;
                for (j = 0; j < r; j++)
                    if (Need[i][j] > Avail[j]) {
                        canRun = 0;
                        break;
                    }
                if (canRun) {
                    proc = i;
                    break;
                }
            }
        }

        if (proc != -1) {
            printf("\nProcess %d runs to completion!", proc + 1);
            Safe[count++] = proc + 1;
            Completed[proc] = 1;

            // release its resources
            for (j = 0; j < r; j++) {
                Avail[j] += Alloc[proc][j];
                Alloc[proc][j] = 0;
                Max[proc][j]   = 0;
                Need[proc][j]  = 0;
            }
        }

    } while (count != p && proc != -1);

    if (count == p) {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence : < ");
        for (i = 0; i < p; i++)
            printf("%d ", Safe[i]);
        printf(">\n");
    } else {
        printf("\nThe system is in an unsafe state!!\n");
    }

    return 0;
}
