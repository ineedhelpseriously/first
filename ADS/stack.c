#include <stdio.h>
int top = -1, max, a[255], Element, i, j, b;

void push()
{
    if (top == max - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed:\n");
        scanf("%d", &Element);
        top++;
        a[top] = Element;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        a[i] = Element;
        printf("%d\n", Element);
    }
}

int main()
{
    int flag = 0;
    printf("Enter the no of elements to be stored:\n");
    scanf("%d", &max);
    while (flag != 1)
    {
        printf("Choose an operation\n1)Push\n2)Pop\n3)Display\n");
        scanf("%d", &j);
        switch (j)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            flag++;
            break;
        default:
            printf("Not an operation\n");
        }
    }
    return 0;
}