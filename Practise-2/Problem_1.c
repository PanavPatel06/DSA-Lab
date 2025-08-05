#include <stdio.h>
struct student
{
    char student_name[100];
    int student_rollno;
    char student_address[100];
};

void print_info(struct student s1)
{
    printf("Name of student is= %s \n",s1.student_name);
    printf("Roll no of student = %d \n",s1.student_rollno);
    printf("The address of student is = %s \n",s1.student_address);
}

void main()
{
    struct student s;
    printf("Enter the name of the student=\n");
    scanf("%s",s.student_name);
    printf("Enter the roll no of student=\n");
    scanf("%d",&s.student_rollno);
    printf("Enter the address of the student=\n");
    scanf("%s",s.student_address);
    print_info(s);
}
