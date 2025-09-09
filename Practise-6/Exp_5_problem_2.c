#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack
{
  int top,size;
  char *array;
}stack;

stack * createstack(int size)
{
  stack *s=(stack *)malloc(sizeof(stack));
  s->array=(char *)malloc(sizeof(char) * size);
  s->top=-1;
  s->size=size;
  return s;
}

int isFull(stack *s)
{
  if(s->top==s->size-1)
    return 1;
  else
    return 0;
}

int isEmpty(stack *s)
{
  if(s->top==-1)
    return 1;
  else
    return 0;
}

void push(stack *s,char item)
{
  if(!isFull(s))
  {
    s->top++;
    s->array[s->top]=item;
  }
}

char pop(stack *s)
{
  if(!isEmpty(s))
  {
    char item=s->array[s->top];
    s->top--;
    return item;
  }
  return '\0';
}

int precedence(char op)
{
  if(op=='+'||op=='-') return 1;
  if(op=='*'||op=='/') return 2;
  if(op=='^') return 3;
  return 0;
}


void infixToPostfix(char *infix,char *postfix)
{
  stack *s=createstack(strlen(infix));
  int i=0,j=0;
  while(infix[i]!='$')
  {
    if(isdigit(infix[i])||isalpha(infix[i]))
    {
      postfix[j++]=infix[i++];
    }
    else if(infix[i]=='(')
    {
      push(s,infix[i++]);
    }
    else if(infix[i]==')')
    {
      while(!isEmpty(s)&&s->array[s->top]!='(')
      {
        postfix[j++]=pop(s);
      }
      if(!isEmpty(s)&&s->array[s->top]=='(')
        pop(s);
      i++;
    }
    else
    {
      while(!isEmpty(s)&&
            ((infix[i]=='^' && precedence(s->array[s->top]) > precedence(infix[i])) ||
             (infix[i]!='^' && precedence(s->array[s->top]) >= precedence(infix[i]))))
      {
        postfix[j++]=pop(s);
      }
      push(s,infix[i++]);
    }
  }
  while(!isEmpty(s))
  {
    postfix[j++]=pop(s);
  }
  postfix[j]='\0';
}

int main()
{
  char infix[100],postfix[100];
  printf("Enter infix expression=");
  scanf("%s",infix);
  int len=strlen(infix);
  infix[len]='$';
  infix[len+1]='\0';
  stack *s=createstack(len+1);
  infixToPostfix(infix,postfix);
  printf("Postfix expression=%s\n",postfix);
  return 0;
}