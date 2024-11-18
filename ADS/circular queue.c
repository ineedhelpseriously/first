

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int is_queue_full()
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int is_queue_empty()
{
    return front == -1; 
}

int enqueue()
{
    if (is_queue_full())
    {
        printf("Error. Queue overflow.\n");
        return -1; 
    }

    int n;
    printf("Enter number to enqueue: ");
    scanf("%d", &n);

    if (front == -1)
    {
        front = 0;
    }

    if (rear == MAX - 1 && front != 0)
    {
        rear = -1;
    }

    // Increment rear and set value.
    rear++;
    queue[rear] = n;
    return rear;
}

int dequeue()
{
    if (is_queue_empty())
    {
        printf("Error: Queue underflow.\n");
        return -1; // Do not run function if queue is empty.
    }

    int n = queue[front]; // Save the value which is to be deleted in separate variable.

    if (front == rear)
    {
        front = rear = -1; // If front has reached rear, i.e. the element deleted is the same as the last inserted element, queue is empty. Set front and rear to -1.
    }

    if (front == MAX - 1)
    {
        front = -1; // If front has reached the end, reset front to -1.
    }

    front++; // Increment front.

    return n;
}

int peek()
{
    if (is_queue_empty())
    {
        printf("Queue underflow.\n");
        return -1;
    }
    printf("%d\n", queue[front]); // Display front value if queue is empty
    return queue[front];
}

int display()
{
    if (is_queue_empty())
    {
        printf("Queue underflow.\n");
        return -1;
    }

    printf("Queue elements are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d\t", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
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