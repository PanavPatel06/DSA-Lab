#include <stdio.h>
int binary_search(int arr[],int n,int x)
{
    int l=0;
    int u=n-1;
    while(l<=u)
    {
        int avg=(l+n)/2;
        if(arr[avg]==x)
        {
            printf("The number is at location= %d",avg+1);
            return 0;
        }
        else if(arr[avg]<x)
        {
            l=avg+1;
        }
        else
        {
            u=avg-1;
        }
    }
    printf("The number was not found in the array");
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
    binary_search(arr,n,x);
}