#include<stdio.h>
#include<stdlib.h>

struct Tnode
{
    int info;
    struct Tnode *left;
    struct Tnode *right;
};

struct Qnode
{
    struct Tnode *data;
    struct Qnode *next;
};

struct Queue
{
    struct Qnode *front, *rear;
};

struct Tnode* createTnode(int i)
{
    struct Tnode* n = (struct Tnode *)malloc(sizeof(struct Tnode));
    if(n == NULL)
    {
        printf("\nMemory is full");
        exit(0);
    }
    n->info = i;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Qnode* createQnode(struct Tnode* t)
{
    struct Qnode* n = (struct Qnode*)malloc(sizeof(struct Qnode));
    if(n == NULL)
    {
        printf("\nMemory is full");
        exit(0);
    }
    n->data = t;
    n->next = NULL;
    return n;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if(q == NULL)
    {
        printf("\nMemory is full");
        exit(0);
    }
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, struct Tnode* t)
{
    struct Qnode* n = createQnode(t);
    if (q->rear == NULL) {
        q->front = q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear = n;
}

struct Tnode* deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return NULL;
    struct Qnode* temp = q->front;
    struct Tnode* TnodeData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return TnodeData;
}

int isQueueEmpty(struct Queue* q)
{
    if(q->front == NULL)
        return 1;
    else
        return 0;
}

void levelOrder(struct Tnode* root)
{
    if (root == NULL)
    {
        printf("\nThe Tree is empty\n");
        return;
    }
    struct Queue* q = createQueue();
    struct Tnode* temp = root;
    enQueue(q, temp);
    printf("\nLevel Order Traversal: ");
    while (!isQueueEmpty(q))
    {
        temp = deQueue(q);
        printf("%d-->", temp->info);
        if (temp->left != NULL)
            enQueue(q, temp->left);
        if (temp->right != NULL)
            enQueue(q, temp->right);
    }
    printf("END\n");
    free(q);
}

// ** NEW FUNCTION TO CREATE THE TREE LEVEL-WISE **
struct Tnode* createTreeLevelWise()
{
    int val;
    struct Tnode* root = NULL;
    struct Queue* q = createQueue();

    printf("\nEnter the value for the root node (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1)
    {
        free(q);
        return NULL;
    }

    root = createTnode(val);
    enQueue(q, root);

    while (!isQueueEmpty(q))
    {
        struct Tnode* current = deQueue(q);

        printf("Enter left child for %d (-1 for no node): ", current->info);
        scanf("%d", &val);
        if (val != -1)
        {
            current->left = createTnode(val);
            enQueue(q, current->left);
        }

        printf("Enter right child for %d (-1 for no node): ", current->info);
        scanf("%d", &val);
        if (val != -1)
        {
            current->right = createTnode(val);
            enQueue(q, current->right);
        }
    }
    printf("\nTree created successfully.\n");
    free(q);
    return root;
}

int main()
{
    struct Tnode* root = NULL;
    while(1)
    {
        int a;
        printf("\nEnter the number for following choices= \n1.Create Tree Level Wise \n2.Display Level Order \n3.To exit\n");
        scanf("%d", &a);

        switch(a)
        {
            case 1:
                root = createTreeLevelWise();
                break;
            case 2:
                levelOrder(root);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                exit(0);
        }
    }
    return 0;
}