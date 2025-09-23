#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
};

struct Node* createNode(int data)
{
 struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
 if(newnode==NULL)
 {
  printf("Not enough memory space\n");
  return NULL;
 }
 newnode->data=data;
 newnode->next=NULL;
 return newnode;
}

void insertFront(struct Node** start,int data)
{
 struct Node* newnode=createNode(data);
 if(newnode==NULL) return;
 newnode->next=*start;
 *start=newnode;
}

void insertEnd(struct Node** start,int data)
{
 struct Node* newnode=createNode(data);
 if(newnode==NULL) return;
 if(*start==NULL)
 {
  *start=newnode;
  return;
 }
 struct Node* temp=*start;
 while(temp->next!=NULL)
 {
  temp=temp->next;
 }
 temp->next=newnode;
}

void insertAfter(struct Node* prev,int data)
{
 if(prev==NULL)
 {
  printf("Empty linked list\n");
  return;
 }
 struct Node* newnode=createNode(data);
 if(newnode==NULL) return;
 newnode->next=prev->next;
 prev->next=newnode;
}

void display(struct Node* start)
{
 if(start==NULL)
 {
  printf("Empty linked list\n");
  return;
 }
 while(start!=NULL)
 {
  printf("%d->",start->data);
  start=start->next;
 }
 printf("\n");
}

int main()
{
 struct Node* start=NULL;
 int ch,data,pos;
 while(1)
 {
  printf("1.Insert at front\n2.Insert at end\n3.Insert after position\n4.Display\n5.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("Enter value:");
    scanf("%d",&data);
    insertFront(&start,data);
    break;
   case 2:
    printf("Enter value:");
    scanf("%d",&data);
    insertEnd(&start,data);
    break;
   case 3:
    printf("Enter position after which to insert:");
    scanf("%d",&pos);
    printf("Enter value:");
    scanf("%d",&data);
    {
     struct Node* temp=start;
     int i=1;
     while(i<pos && temp!=NULL)
     {
      temp=temp->next;
      i++;
     }
     insertAfter(temp,data);
    }
    break;
   case 4:
    display(start);
    break;
   case 5:
    exit(0);
  }
 }
}