#include <stdio.h>
#include <string.h>

struct {
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir;

int main() {
    int ch, i;
    char f[10];

    dir.fcnt = 0;
    printf("Enter name of directory -- ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n1. Create File  2. Delete File  3. Search File");
        printf("\n4. Display Files  5. Exit");
        printf("\nEnter your choice -- ");
        scanf("%d", &ch);

        if (ch == 1) {                         // create
            printf("\nEnter the name of the file -- ");
            scanf("%s", dir.fname[dir.fcnt++]);
        }

        else if (ch == 2) {                    // delete
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
                if (strcmp(dir.fname[i], f) == 0) {
                    printf("File %s is deleted\n", f);
                    for (; i < dir.fcnt - 1; i++)
                        strcpy(dir.fname[i], dir.fname[i+1]);
                    dir.fcnt--;
                    break;
                }
            if (i == dir.fcnt)
                printf("File %s not found\n", f);
        }

        else if (ch == 3) {                    // search
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);
            for (i = 0; i < dir.fcnt; i++)
                if (strcmp(dir.fname[i], f) == 0) break;
            printf("File %s %s\n", f, (i < dir.fcnt) ? "is found" : "not found");
        }

        else if (ch == 4) {                    // display
            if (!dir.fcnt) printf("\nDirectory Empty");
            else {
                printf("\nThe Files are --  ");
                for (i = 0; i < dir.fcnt; i++)
                    printf("%s  ", dir.fname[i]);
            }
        }

        else if (ch == 5)
            break;
    }
    return 0;
}
