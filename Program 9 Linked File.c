#include <stdio.h>

int main() {
    int f[50] = {0};
    int p, i, st, len, j, more;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &j);
        if (j >= 0 && j < 50) f[j] = 1;
    }

    do {
        printf("\nEnter starting block and length of file: ");
        scanf("%d%d", &st, &len);

        if (f[st]) {
            printf("%d starting block is already allocated\n", st);
        } else {
            int fail = 0;
            for (j = st; j < st + len && j < 50; j++) {
                if (f[j] == 0) {
                    f[j] = 1;
                    printf("%d --> allocated\n", j);
                } else {
                    printf("%d block is already allocated\n", j);
                    fail = 1;
                }
            }
            if (!fail) printf("File allocated from %d to %d\n", st, st + len - 1);
        }

        printf("Do you want to enter more file (Yes-1 / No-0): ");
        scanf("%d", &more);
    } while (more == 1);

    return 0;
}
