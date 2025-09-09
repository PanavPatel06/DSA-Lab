#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack
{
  int top,size;
  int *array;
}stack;

stack * createstack(int size)
{
  stack *s=(stack *)malloc(sizeof(stack));
  s->array=(int *)malloc(sizeof(int) * size);
  s->top=-1;
  s->size=size;
  return s;
}

int isFull(stack *s)
{
  if(s->top==s->size-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty(stack *s)
{
  if(s->top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void push(stack *s,int item)
{
  if(!isFull(s))
  {
    s->top++;
    s->array[s->top]=item;
  }
}

int pop(stack *s)
{
  if(!isEmpty(s))
  {
    int item=s->array[s->top];
    s->top--;
    return item;
  }
  return 0;
}

int evaluate(char *expr,stack *s)
{
  int i=0;
  while(expr[i]!=')')
  {
    if(isdigit(expr[i]))
    {
      push(s,expr[i]-'0');
    }
    else
    {
      int A=pop(s);
      int B=pop(s);
      switch(expr[i])
      {
        case '+':push(s,B+A);break;
        case '-':push(s,B-A);break;
        case '*':push(s,B*A);break;
        case '/':push(s,B/A);break;
        case '^':push(s,B^A);break;
      }
    }
    i++;
  }
  return pop(s);
}

int main()
{
  char expr[100];
  printf("Enter single digit postfix expression:");
  scanf("%s",expr);
  int len=strlen(expr);
  expr[len]=')';
  expr[len+1]='\0';
  stack *s=createstack(len+1);
  int result=evaluate(expr,s);
  printf("Result=%d\n",result);
  return 0;
}