#include <stdio.h>

int main()
{
    // array of pointers
    int *p[5];
    int arr[5];
    printf("Enter 5 integers where the pointer should be pointing=\n");
    for (int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        p[i]=&arr[i];
    }
    printf("The array of integers contains following elements=\n");
    for (int i=0;i<5;i++)
    {
        printf("%d\n",*p[i]);
    }

    // pointer to array
    int *q=arr;
    printf("Printing the array with the use of pointer=");
    for (int i=0;i<5;i++)
    {
        printf("\n%d",*(q+i));
    }
}