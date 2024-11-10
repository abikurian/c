#include <stdio.h>
#define size 5
void main()
{
    int q[size], front = -1, rear = -1, i, ch, e, cont;
    printf("Menu: ");
    printf("\n 1. Enque\n 2. Deque\n 3. Display \n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            if (rear == size - 1)
            {
                printf("Queue is full\n");
                break;
            }
            else
            {
                printf("Enter the element to be inserted: ");
                scanf("%d", &e);
                if (front == -1)
                {
                    front = 0;
                }
                rear++;
                q[rear] = e;
            }
            break;
        }

        case 2:
        {
            if (front == -1 || front > rear)
            {
                printf("Queue is empty\n");
            }
            else
            {
                e = q[front];
                printf("The dequed element is: %d\n", e);
                front++;
                if (front > rear)
                {
                    front = rear = -1;
                }
            }
            break;
        }

        case 3:
        {
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("The element of the queue are: \n");
                for (int i = front; i <= rear; i++)
                {
                    printf("%d \t", q[i]);
                }
                printf("\n");
            }
            break;
        }

        default:
            break;
        }
        printf("Enter 1 to continue ");
        scanf("%d", &cont);
    } while (cont == 1);
}