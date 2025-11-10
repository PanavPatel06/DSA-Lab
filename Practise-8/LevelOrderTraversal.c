#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * right,* left;
};

struct node * root;

struct node* createNode(int data) 
{
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct queueNode
{
    struct node * ptr;
    struct queueNode * next;
};

struct queueNode * forw = NULL, * rear = NULL;

struct queueNode * createQueueNode(struct node *p)
{
    struct queueNode * n=(struct queueNode *)malloc(sizeof(struct queueNode));
    n->ptr = p;
    n->next=NULL;
    return n;
}

struct node * createTree()
{
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) 
        return NULL;

    struct node* temp = createNode(data);

    printf("Enter left child of %d\n", data);
    temp->left = createTree();

    printf("Enter right child of %d\n", data);
    temp->right = createTree();

    return temp;
}

void enqueue(struct node * pointer)
{
    struct queueNode * n = createQueueNode(pointer);

    if(forw == NULL) // queue empty
    {
        forw = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

struct node * dequeue()
{
    if(forw == NULL)
        return NULL;

    struct queueNode * temp = forw;
    struct node * p = temp->ptr;

    forw = forw->next;
    free(temp);

    return p;
}

int displayLevelOrder(struct node * root)
{
    if(root == NULL)
    {
        printf("\nTree does not exist");
        return 0;
    }

    enqueue(root);

    printf("\nLevel Order Traversal: ");

    while(forw != NULL)
    {
        struct node * current = dequeue();
        printf("%d ", current->data);

        if(current->left != NULL)
            enqueue(current->left);

        if(current->right != NULL)
            enqueue(current->right);
    }

    printf("\n");
    return 0;
}

int main()
{
    int a;

    while(1)
    {
        printf("\nEnter the number for following choices \n1.Create Tree \n2.Display level order \n3.Exit\n");
        scanf("%d",&a);

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

            default:
                printf("Invalid Choice");
                break;
        }
    }
    return 0;
}