#include <stdio.h>

int main()
{
    char user[5][20], file[5][20];
    int n, i;

    printf("Enter number of users: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter User Name: ");
        scanf("%s", user[i]);

        printf("Enter File Name: ");
        scanf("%s", file[i]);
    }

    printf("\nTwo Level Directory\n");

    for(i=0;i<n;i++)
        printf("%s --> %s\n", user[i], file[i]);

    return 0;
}
