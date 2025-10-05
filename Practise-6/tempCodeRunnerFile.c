#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Stack
{
 int top,size;
 char *array;
};

struct Stack* createStack(int size)
{
 struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
 s->size=size;
 s->top=-1;
 s->array=(char*)malloc(sizeof(char)*size);
 return s;
}

int isEmpty(struct Stack* s)
{
 return s->top==-1;
}

void push(struct Stack* s,char c)
{
 s->array[++s->top]=c;
}

char pop(struct Stack* s)
{
 return s->array[s->top--];
}

char peek(struct Stack* s)
{
 return s->array[s->top];
}

int prec(char c)
{
 if(c=='^') return 3;
 if(c=='*'||c=='/') return 2;
 if(c=='+'||c=='-') return 1;
 return -1;
}

void infixToPostfix(char* expr)
{
 struct Stack* s=createStack(strlen(expr));
 int i,k=-1;
 char *res=(char*)malloc(strlen(expr)+1);
 for(i=0;expr[i];i++)
 {
  if(isalnum(expr[i]))
  {
   res[++k]=expr[i];
  }
  else if(expr[i]=='(')
  {
   push(s,expr[i]);
  }
  else if(expr[i]==')')
  {
   while(!isEmpty(s)&&peek(s)!='(')
   {
    res[++k]=pop(s);
   }
   pop(s);
  }
  else
  {
   while(!isEmpty(s)&&prec(peek(s))>=prec(expr[i]))
   {
    res[++k]=pop(s);
   }
   push(s,expr[i]);
  }
 }
 while(!isEmpty(s))
 {
  res[++k]=pop(s);
 }
 res[++k]='\0';
 printf("%s\n",res);
}

int main()
{
 char expr[100];
 printf("Enter single digit postfix expression=");
 scanf("%s",expr);
 infixToPostfix(expr);
 return 0;
}