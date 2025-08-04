#include <stdio.h>
int bubble_sort(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        for(int i=0;i<n;i++)
        {
            int count=0;
            int temp;
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            else
            {
                count=count+1;
                if(count==n-1)
                {
                    goto lable;
                }
            }
        }
    }
    lable:
    printf("The sorted array is = ");
    for (int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter the number of elements in array=");
    scanf("%d",&n);
    printf("Enter the elements for the array=");
    int arr[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
}