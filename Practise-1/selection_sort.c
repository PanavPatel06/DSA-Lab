#include <stdio.h>
int selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min])
            {
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    printf("The sorted array is = ");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter the number of elements in array=");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements for the array=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
}
