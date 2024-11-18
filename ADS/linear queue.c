

#include <stdio.h>
#define MAX 5

int queue[MAX];

int front = -1, rear = -1;

int is_overflow()
{
    if (rear == MAX - 1)
    {
        printf("Error. Queue overflow.\n");
        return 1;
    };
    return 0;
}

int is_underflow()
{
    if (front == -1 || front > rear)
    {
        printf("Error: Queue underflow.\n");
        return 1;
    }
    return 0;
}

int enqueue()
{
    if (is_overflow())
    {
        return -1;
    }

    int n;
    printf("Enter number to enqueue: ");
    scanf("%d", &n);

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = n;
    return rear;
}

int dequeue()
{
    if (is_underflow())
    {
        return -1;
    }

    int n = queue[front];

    front++;

    return n;
}

int peek()
{
    if (is_underflow())
    {
        return -1;
    }
    printf("%d", queue[front]);
    return queue[front];
}

int display()
{
    if (is_underflow())
    {
        return -1;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
    return 1;
}

int main()
{
    int run = 1;
    while (run)
    {
        int choice = 0;

        printf("Options:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
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
        case 5:
            run = 0;
            break;
        default:
            printf("Please choose an appropriate option. \n");
            break;
        }
    }
    return 0;
}