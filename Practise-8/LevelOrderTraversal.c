#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node * right,* left;
};

struct node * root;

struct node* createNode(int data) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct  queueNode
{
  struct node * ptr;
  struct queueNode * next;
};

struct queueNode * forw,* rear;

struct node * createQueueNode()
{
  struct n *=(struct queueNode)malloc(sizeof(struct queueNode))
}

struct node * createTree()
{
  int data;
  printf("Enter data (-1 for no node): ");
  scanf("%d", &data);

  if (data == -1) return NULL;

  struct node* root = createNode(data);
  printf("Enter left child of %d\n", data);
  root->left = createTree();

  printf("Enter right child of %d\n", data);
  root->right = createTree();

  return root;
}

void displayLevelOrder(struct node * root)
{
  struct node * ptr;
  ptr=root;
  // ptr=enqueue(root->info,ptr);
  while(ptr!=NULL)
  {
    enqueue(ptr);
  }
}

int main()
{
  int a;
  struct node * root;
  printf("\nEnter the number for following choices \n1.Create Tree \n2.Display level order \n3.Exit\n");
  scanf("%d",&a);
  while(1)
  {
    switch(a)
    {
      case 1:
        root=createTree();
        break;
      case 2:
        displayLevelOrder(root);
        break;
      case 3:
        exit(0);
        break;
      default:
        printf("Invalid Choice");
        break;
    }
  }
  return 0;
}