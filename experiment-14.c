#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, choice;
    char files[20][30], fname[30];

    n = 0;

    while (1)
    {
        printf("\n1.Create File\n2.Display Files\n3.Search File\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter file name: ");
            scanf("%s", files[n]);
            n++;
            break;

        case 2:
            printf("\nFiles in Directory:\n");
            for (i = 0; i < n; i++)
                printf("%s\n", files[i]);
            break;

        case 3:
            printf("Enter file to search: ");
            scanf("%s", fname);

            for (i = 0; i < n; i++)
            {
                if (strcmp(files[i], fname) == 0)
                {
                    printf("File Found\n");
                    break;
                }
            }

            if (i == n)
                printf("File Not Found\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
