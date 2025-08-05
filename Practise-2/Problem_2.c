#include <stdio.h>
struct student
{
    char student_name[100];
    int student_rollno;
    char student_address[100];
};

void print_info(struct student s1[])
{
    for(int i=0;i<2;i++)
    {
        printf("Name of student is= %s \n",s1[i].student_name);
        printf("Roll no of student = %d \n",s1[i].student_rollno);
        printf("The address of student is = %s \n",s1[i].student_address);
    }
}

void main()
{
    struct student s[2];
    printf("Enter the details for 5 student\n");
    for(int i=0;i<2;i++)
    {
        printf("Enter the name of the student=\n");
        scanf("%s",s[i].student_name);
        printf("Enter the roll no of student=\n");
        scanf("%d",&s[i].student_rollno);
        printf("Enter the address of the student=\n");
        scanf("%s",s[i].student_address);
    }
    print_info(s);
}
