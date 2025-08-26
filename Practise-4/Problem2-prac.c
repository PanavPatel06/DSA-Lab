#include<stdio.h>
#include<stdlib.h>

struct Stack
{
  int top,size;
  int *array;
};

struct Stack* createStack(int size)
{
  struct Stack *s=(struct Stack *) malloc(sizeof(struct Stack));
  s->size=size;
  s->top=0;
  s->array=(int *)malloc(sizeof(int)*size);
  return s;
}

int isEmpty(struct Stack *s)
{
  if(s->top==0)
  {
    printf("The stack is Empty\n");
    return 1;
  }
  else
  {
    printf("The stack is not empty\n");
    return 0;
  }
}

int isFull(struct Stack *s)
{
  if(s->top==s->size)
  {
    printf("The stack is full\n");
    return 1;
  }
  else
  {
    printf("The stack is not full\n");
    return 0;
  }
}

int push(struct Stack *s)
{
  int item1;
  int g=isFull(s);
  if(g==0)
  {
    printf("Enter the value that is to be pushed=");
    scanf("%d",&item1);
    s->array[s->top]=item1;
    s->top=s->top+1;
    printf("Pushed the element to stack\n");
    return 0;
  }
  return 0;
}

int pop(struct Stack *s)
{
  int p=isEmpty(s);
  if(p==0)
  {
    s->top=s->top-1;
    printf("The element was poped\n");
    return 0;
  }
  return 0;
}

void print_top(struct Stack *s)
{
  printf("The topmost element is %d\n",s->array[s->top-1]);
}

int main()
{
  
}