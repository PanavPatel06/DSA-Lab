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

void deleteFront(struct Node** start)
{
 if(*start==NULL)
 {
  printf("Empty linked list\n");
  return;
 }
 struct Node* temp=*start;
 *start=(*start)->next;
 free(temp);
}

void deleteEnd(struct Node** start)
{
 if(*start==NULL)
 {
  printf("Empty linked list\n");
  return;
 }
 if((*start)->next==NULL)
 {
  free(*start);
  *start=NULL;
  return;
 }
 struct Node* temp=*start;
 while(temp->next->next!=NULL)
 {
  temp=temp->next;
 }
 free(temp->next);
 temp->next=NULL;
}

void deleteAfter(struct Node* prev)
{
 if(prev==NULL||prev->next==NULL)
 {
  printf("Empty linked list or invalid position\n");
  return;
 }
 struct Node* temp=prev->next;
 prev->next=temp->next;
 free(temp);
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
  printf("1.Insert for setup\n2.Delete front\n3.Delete end\n4.Delete after position\n5.Display\n6.Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("Enter value:");
    scanf("%d",&data);
    {
     struct Node* newnode=createNode(data);
     if(newnode==NULL) break;
     if(start==NULL)
     {
      start=newnode;
     }
     else
     {
      struct Node* temp=start;
      while(temp->next!=NULL) temp=temp->next;
      temp->next=newnode;
     }
    }
    break;
   case 2:
    deleteFront(&start);
    break;
   case 3:
    deleteEnd(&start);
    break;
   case 4:
    printf("Enter position after which to delete:");
    scanf("%d",&pos);
    {
     struct Node* temp=start;
     int i=1;
     while(i<pos && temp!=NULL)
     {
      temp=temp->next;
      i++;
     }
     deleteAfter(temp);
    }
    break;
   case 5:
    display(start);
    break;
   case 6:
    exit(0);
  }
 }
}