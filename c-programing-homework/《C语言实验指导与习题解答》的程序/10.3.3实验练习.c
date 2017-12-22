#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
struct student
{
    long num;
    char name[10];
    int age;
    char address[10];
}stu[SIZE], out;
int len;
void fsave()
{
    FILE *fp;
    int i;
    if ((fp = fopen("student.dat", "wb")) == NULL)
        {
            printf("Cannot open file.\n");
            exit(0);
        }
    for (i = 0; i < SIZE; i++)
        if((fwrite(&stu[i], len, 1, fp)) < 1)
            printf("File write error.\n");
    fclose(fp);
} 

int main()
{
    FILE *fp;
    int i;
    len = sizeof(struct student);
    for (i = 0; i < SIZE; i++)
    {
        printf("Input student %d:", i+1);
        scanf("%ld %s %d %s", &stu[i].num, stu[i].name,
                              &stu[i].age, stu[i].address);
    }
    fsave();
    fp = fopen("student.dat", "rb");
    printf("No. Name          Age Address\n");
    while (!feof(fp))
    {
        fread(&out, len, 1, fp);
        printf("%-4ld %-10s %4d %-15s\n", out.num, out.name,
                                         out.age, out.address);
    }
    fclose(fp);
    return 0;
}
