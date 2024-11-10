#include <stdio.h>
void main()
{
    int size = 5;
    int cq[size], front = 0, rear = 0, i, ch, item, cont;
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

            if (next != front)
            {
                printf("\nEnter the item to be inserted: ");
                scanf("%d", &item);
                if (front == -1)
                {
                    front = rear = 0;
                }
                else
                {
                    rear = (rear % size) + 1;
                }
                cq[rear] = item;
            }
            else
            {
                printf("Queue is full \n");
            }
        }
        break;
        case 2:
        {
            if (front == 0)
            {
                printf("queue is empty \n");
            }
            else
            {
                item = cq[front];
                front = (front % size) + 1;
            }
            break;
        }
        case 3:
        {
            if (front == 0)
            {
                printf("Queue is empty \n");
            }
            else
            {
                printf("Queue elements are: ");
                for (i = front; i <= rear; i++)
                {
                    printf("%d ", cq[i]);
                }
                printf("\n");
            }
            break;
        }
        }
        printf("Print 1 to continue: ");
        scanf("%d", &cont);
    } while (cont == 1);
}
