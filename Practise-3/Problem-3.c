#include<stdio.h>
int swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
  printf("The swapped number is= %d %d",*a,*b);
  return 0;
}

int main()
{
  int p,q;
  printf("Enter two number=");
  scanf("%d %d",&p,&q);
  swap(&p,&q);
  return 0;
}