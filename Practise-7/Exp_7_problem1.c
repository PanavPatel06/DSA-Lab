#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node* next;
};

struct node* createnode(int i)
{
  struct node* n=(struct node *)malloc(sizeof(struct node));
  if(n==NULL)
  {
    printf("\nMemory is full");//OverflowCondition
    exit(0);
  }
  n->info=i;
  return n;
}

struct node * insertAtEnd(int i,struct node * start)
{
  struct node* temp;
  temp=start;
  struct node *n=createnode(i);
  n->info=i;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
  n->next=NULL;
  return start;
}

struct node * insertAtBeginning(int i,struct node * start)
{
  struct node *n=createnode(i);
  n->info=i;
  n->next=start;
  start=n;
  return start;
}

struct node * insertInBetween(int i,int loc,struct node * start)
{
  if(loc==1)
  {
    start=insertAtBeginning(i,start);
    return start;
  }
  struct node *temp;
  temp=start;
  while(loc>=3)
  {
    temp=temp->next;
    if(temp==NULL)
    {
      start=insertAtEnd(i,start);
      return start;
    }
    loc--;
  }
  struct node *n=createnode(i);
  n->info=i;
  n->next=temp->next;
  temp->next=n;
  return start;
}

int display(struct node * start)
{
  struct node* temp;
  temp=start;
  while(temp!=NULL)
  {
    printf("%d-->",temp->info);
    temp=temp->next;
  }
  printf("NULL\n");
  return 0;
}

int main()
{
  struct node * start=NULL;
  while(1)
  {
    struct node * n;
    int a,b;
    printf("Enter the number for following choices= \n1.Insert a node at end \n2.Insert a node at beginning \n3.Insert a node in between \n4.Display Linked list \n5.To exit\n");
    scanf("%d",&a);
    switch(a)
    {
      case 1:
      printf("\nEnter the number to be stored=");
      scanf("%d",&b);
        if(start==NULL)
        {
          printf("\nCreating first node");
          struct node *n=createnode(b);
          start=n;
          n->next=NULL;
        }
        else
        {
          start=insertAtEnd(b,start);
        }
        break;
      case 2:
        printf("\nEnter the number to be stored=");
        scanf("%d",&b);
        if(start==NULL)
        {
          printf("\nCreating first node");
          struct node *n=createnode(b);
          start=n;
          n->next=NULL;
        }
        else
        {
          start=insertAtBeginning(b,start);
        }
        break;
      case 3:
        printf("\nEnter the number to be stored=");
        scanf("%d",&b);
        int pos;
        printf("\nEnter the location at which you want to insert starting from 1=");
        scanf("%d",&pos);
        if(start==NULL)
        {
          printf("\nCreating first node");
          struct node *n=createnode(b);
          start=n;
          n->next=NULL;
        }
        else
        {
          start=insertInBetween(b,pos,start);
        }
        break;
      case 4:
        display(start);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice");
    }
  }
}