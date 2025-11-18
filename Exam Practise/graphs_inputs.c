#include<stdio.h>
#include<stdlib.h>

struct nodelist
{
  int data;
  struct nodelist * next;
  struct edgelist * e;
};

struct nodelist * start;

struct edgelist
{
  int data;
  struct edgelist * next;
};

struct nodelist * createnode(int val,struct nodelist * prev)
{
  struct nodelist * n=(struct nodelist *)malloc(sizeof(struct nodelist));
  if(n==NULL)
  {
    printf("\nMemory got full");
    return NULL;
  }
  n->data=val;
  prev->next=n;
  n->next=NULL;
  n->e=NULL;
  return n;
}

void insertAtBeginning(struct nodelist * temp,struct edgelist * n)
{
  temp->e=n;
}

void insertAtEnd(struct edgelist * temp1,struct edgelist * n )
{
  temp1->next=n;
}

void createedgenode(int src,int des)
{
  struct nodelist * temp=NULL;
  struct edgelist * temp1=NULL;
  temp=start;
  struct edgelist * n=(struct edgelist *)malloc(sizeof(struct edgelist));
  if(n==NULL)
  {
    printf("\nMemory got full");
    exit(0);
  }
  n->data=des;
  n->next=NULL;
  while(temp->data!=src)
  {
    temp=temp->next;
  }
  if(temp->e==NULL)
  {
  insertAtBeginning(temp,n);//temp->e=n;
  }
  else
  {
    temp1=temp->e;
    while(temp1->next!=NULL)
    {
      temp1=temp1->next;
    }
    insertAtEnd(temp1,n);//temp1->next=n;
  }
}

void creategraph(int m,int n)
{
  struct nodelist * prev=NULL;
  for(int i=0;i<n;i++)
  {
    int num;
    printf("\nEnter the value of vertex=");
    scanf("%d",&num);
    if(i==0)
    {
      struct nodelist * n=(struct nodelist *)malloc(sizeof(struct nodelist));
      if(n==NULL)
      {
        printf("\nMemory got full");
        exit(0);
      }
      n->data=num;
      n->next=NULL;
      n->e=NULL;
      start=n;
      prev=start;
    }
    else
    {
      prev=createnode(num,prev);
    }
  }

  printf("Enter the edges in the format(source dest)=");
  for (int j=0;j<m;j++)
  {
    int source,dest;
    scanf("%d %d", &source, &dest);
    createedgenode(source,dest);
  }
}

int main()
{
  int n,m;
  printf("Enter the number of vertices =\n");
  scanf("%d",&n);
  printf("\nEnter the number of edges=");
  scanf("%d",&m);
  creategraph(m,n);
}