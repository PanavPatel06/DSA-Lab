// linear search
#include<stdio.h>

int linear_search()

void main()
{
    int flag=0;
    int arr[]={1,2,4,8,9};
    for (int i=0;i<5;i++)
    {
        if(arr[i]==4)
        {
            flag=1;
            printf("The search is successful");
            break;
        }
    }
    if(flag==0)
    {
        printf("Search was not successful");
    }
}