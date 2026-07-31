#include <stdio.h>

struct emp
{
    int id;
    char name[20];
    float sal;
};

int main()
{
    FILE *fp;
    struct emp e;

    fp = fopen("emp.dat","wb+");

    printf("Enter ID Name Salary: ");
    scanf("%d%s%f",&e.id,e.name,&e.sal);

    fwrite(&e,sizeof(e),1,fp);

    rewind(fp);

    fread(&e,sizeof(e),1,fp);

    printf("\nID : %d\nName : %s\nSalary : %.2f\n",
           e.id,e.name,e.sal);

    fclose(fp);

    return 0;
}
