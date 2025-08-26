#include <stdio.h>

int linear_search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            printf("The number is at location= %d",i+1);
            return 0;
        }
    }
    printf("The number was not found");
    return 0;
}

void main()
{
    int n,x;
    printf("Enter the number of elements in array=");
    scanf("%d",&n);
    printf("Enter the elements for the array=");
    int arr[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number that you want to search=");
    scanf("%d",&x);
    linear_search(arr,n,x);
}