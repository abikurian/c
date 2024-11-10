#include <stdio.h>
void main()
{
    int stack[50], top = -1, i, size = 5, ch, cont, e;
    do
    {
        printf(" 1. Push \n 2. Pop \n 3. Display \n Enter a choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (top == size - 1)
            {
                printf("Stack is full \n");
            }
            else
            {
                top++;
                printf("Enter the element to be pushed \n");
                scanf("%d", &e);
                stack[top] = e;
            }
            break;
        case 2:
            if (top == -1)
            {
                printf("Stack is empty \n");
            }
            else
            {
                e = stack[top];
                top--;
                printf("Popped element is %d \n", e);
                break;
            }
        case 3:
            printf("The stacked elements are: ");
            for (i = 0; i <= top; i++)
            {
                printf("%d\t", stack[i]);
            }
            printf("\n");
            break;
        }
        printf("Press 1 to continue \n");
        scanf("%d", &cont);
    } while (cont == 1);
}