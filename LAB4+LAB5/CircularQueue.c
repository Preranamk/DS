#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void peek();
void display();

int main()
{
    int ch;
    int x;
    do
    {
        printf("Enter choice 1: Enqueue\n 2: Dequeue\n 3: Peek\n 4: Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value of x: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 0);

    return 0;
}

void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue is Full!!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("Insertion successful\n");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("Insertion successful\n");
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!!!\n");
    }
    else if (front == rear)
    {
        printf("%d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d\n", queue[front]);
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        } while (i != (rear + 1) % N);
        printf("\n");
    }
}


