#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int f,r,size;
    int * array;
};

struct queue * createQueue(int size)
{
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->f=-1;
    q->r=-1;
    q->array=(int *)malloc(sizeof(int)*size);
    return q;
};

int isEmpty(struct queue *q)
{
    if(F=-1)
    {
        printf("The queue is empty");
        return 0;
    }
    return 1;
}

int Enqueue(struct queue *q)
{
    int item;
    printf("Enter the number you want to insert=");
    scanf("%d",&item);
    if(isEmpty(q)==1)
    {
        q->f++;
        q->r++;
        q->array[q->f]=item;
    }
    else if(q->r<q->size-1)
    {
        q->array[q->r]=item;
    }
    else
    {
        q->r=0;
    }
}

int main()
{
    int size,i;
    printf("Enter the size for queue=")
    scanf("%d",&size);
    struct queue *q=createQueue(size)
    printf("Enter a number for the following choice=\n");
    while(1)
    {
        printf("1.To check for empty queue \n2.To check if queue is full \n3.To insert element \n4.To delete element \n5.To print front and rear element \n6.To exit");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                isEmpty(q);
                break;
            case 2:
                isFull(q);
                break;
            case 3:
                Enqueue(q);
                break;
            case 4:
                Dequeue(q);
                break;
            case 5:
                print(q);
                break;
            case 6:
                exit(0);
                break;
        }
    }
}
