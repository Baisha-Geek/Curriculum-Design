#include <stdio.h>
#include <stdlib.h>
struct student
{
    long num;
    char name[10];
    int age;
    char address[10];
};

int main()
{
    struct student stud;
    FILE *fp;
    int i;
    printf("请输入学生的学号：");
    scanf("%d", &i);
    if ((fp = fopen("student.dat", "rb")) == NULL)
        {
            printf("Cannot open file.\n");
            exit(0);
        }
    fseek(fp, (i-1)*sizeof(struct student), 0);
    if ((fread(&stud, sizeof(struct student), 1,fp)) != 0)
        printf("%ld, %s, %d, %s\n", stud.num, stud.name, stud.age, stud.address);
    fclose(fp);
    return 0;
}
