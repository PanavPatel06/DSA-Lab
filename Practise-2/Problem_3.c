#include <stdio.h>
//error in this code
struct organisation
{
    char Organization_name[100];
    int Organization_id;
    struct employee
    {
        int employee_id;
        char employee_name[100];
        int employee_salary;
    }e[2];
};

void print_info(struct organisation o[])
{
    for(int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            printf("%s works in organization %s with id %s and his id is %d and his salary is %d",o[i].e[j].employee_name,o[i].Organization_name,o[i].Organization_id,o[i].e[j].employee_id,o[i].e[j].employee_salary);
        }
    }
}

void main()
{
    struct organisation o[2];
    for(int i=0;i<2;i++)
    {
        printf("Enter the name of Organization =\n");
        scanf("%s",o[i].Organization_name);
        printf("Enter the id of Organization =\n");
        scanf("%d",&o[i].Organization_id);
        printf("Enter the details of the employee for the above organization=\n");
        for(int j=0;j<2;j++)
        {
            printf("Enter the name of employee in the organization %s=",o[i].Organization_name);
            scanf("%s",o[i].e[j].employee_name);
            printf("Enter the id of employee in the organization %s=",o[i].Organization_name);
            scanf("%d",&o[i].e[j].employee_id);
            printf("Enter the salary of employee in the organization %s=",o[i].Organization_name);
            scanf("%d",o[i].e[j].employee_salary);
        }
    }
    print_info(o);
}
