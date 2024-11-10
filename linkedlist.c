#include <stdio.h> //LINKED LIST
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *I, *first = NULL, *last = NULL, *current, *prev;

int main()
{
    int item;

    int ch, cont;
    do
    {
        printf("Enter your choice:\n 1. Create\n  2. Insertion last \n 3. Insertion at first\n 4. Insertion in between\n 5. Deletion \n 6. Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // creation
        {
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            I = (struct node *)malloc(sizeof(struct node));
            I->data = item;
            I->link = NULL;
            if (first == NULL)
            {
                first = last = I;
            }
            else
            {
                last->link = I;
                last = I;
            }
            break;
        }
        case 2: // creation
        {
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            I = (struct node *)malloc(sizeof(struct node));
            I->data = item;
            I->link = NULL;
            if (first == NULL)
            {
                first = last = I;
            }
            else
            {
                last->link = I;
                last = I;
            }
            break;
        }
        case 3: // insertion at first
        {
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            I = (struct node *)malloc(sizeof(struct node));
            I->data = item;
            I->link = NULL;
            if (first == NULL)
            {
                first = last = I;
            }
            else
            {
                I->link = first;
                first = I;
            }
            break;
        }
        case 4: // insertion in between
        {
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            I = (struct node *)malloc(sizeof(struct node));
            I->data = item;
            I->link = NULL;
            int pos;
            printf("Enter the position to be inserted: ");
            scanf("%d", &pos);
            current = first;
            while (current->data != pos && current != NULL)
            {
                current = current->link;
            }
            if (first == NULL)
            {
                first = last = I;
            }
            else if (current == first)
            {
                first->link = I;
                last = I;
            }
            else if (current == last)
            {
                last->link = I;
                last = I;
            }
            else
            {
                I->link = current->link;
                current->link = I;
            }
            break;
        }
        case 5: // deletion
        {
            int del;
            printf("Enter the data to be deleted: ");
            scanf("%d", &del);
            current = first;
            while (current->data != del && current != NULL)
            {
                prev = current;
                current = current->link;
            }
            if (first == NULL) // empty linked list condition
            {
                printf("Empty Linked List");
            }
            else if (current == NULL) // Element not found condition
            {
                printf("NODE NOT FOUND");
            }
            else if (current == first) // deletion first condition
            {
                first = first->link;
            }
            else if (current == last) // deletion last condition
            {
                last = prev;
            }
            else // deletion between condition
            {
                prev->link = current->link;
                free(current);
            }
            break;
        }
        case 6: // display
        {
            current = first;
            while (current != NULL)
            {
                printf("%d \t", current->data);
                current = current->link;
            }
            printf("\n");
            break;
        }
        }
        printf("Press 1 to continue: ");
        scanf("%d", &cont);
    } while (cont == 1);
}
