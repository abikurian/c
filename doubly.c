#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
} *I, *first = NULL, *last = NULL, *current, *prev = NULL;

int main()
{
    int ch, con, pos, item;
    do
    {
        printf("Menu:\n1. Insertion at first\n2. Insertion at last\n3. Insertion at intermediate right\n4. Insertion at intermediate left\n5. Deletion at first\n6. Deletion at last\n7. Deletion at intermediate position\n8. Display forward\n9. Display backward\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // Insert at first
            I = (struct Node *)malloc(sizeof(struct Node *));
            printf("Enter the data: ");
            scanf("%d", &item);
            I->data = item;
            I->llink = NULL;
            I->rlink = NULL;
            if (first == NULL)
            {
                first = last = I;
            }
            else
            {
                first->llink = I;
                I->rlink = first;
                first = I;
            }
            break;

        case 2: // Insert at last
            I = (struct Node *)malloc(sizeof(struct Node *));
            printf("Enter the data: ");
            scanf("%d", &item);
            I->data = item;
            I->llink = NULL;
            I->rlink = NULL;
            if (first == NULL)
            {
                first = last = I;
            }
            else
            {
                last->rlink = I;
                I->llink = last;
                last = I;
            }
            break;

        case 3: // Insert Intermediate Right
            I = (struct Node *)malloc(sizeof(struct Node *));
            printf("Enter item where u want to enter: ");
            scanf("%d", &pos);
            printf("Enter the data: ");
            scanf("%d", &item);
            I->data = item;
            I->llink = NULL;
            I->rlink = NULL;
            current = first;
            while (current->data != pos)
            {
                current = current->rlink;
            }
            I->rlink = current->rlink;
            current->rlink->llink = I;
            I->llink = current;
            current->rlink = I;
            break;

        case 4: // Insert Intermediate Left
            I = (struct Node *)malloc(sizeof(struct Node *));
            printf("Enter item where u want to enter: ");
            scanf("%d", &pos);
            printf("Enter the data: ");
            scanf("%d", &item);
            I->data = item;
            I->llink = NULL;
            I->rlink = NULL;
            current = first;
            while (current->data != pos)
            {
                current = current->rlink;
            }
            I->llink = current->llink;
            current->llink->rlink = I;
            I->rlink = current;
            current->llink = I;
            break;

        case 5: // Delete at first
            if (first == NULL)
            {
                printf("Linked list is empty.\n");
            }
            else
            {
                first = first->rlink;
                first->llink = NULL;
            }
            break;

        case 6: // Delete at last
            if (first == NULL)
            {
                printf("Linked list is empty.\n");
            }
            else
            {
                last = last->llink;
                last->rlink = NULL;
            }
            break;

        case 7: // Delete at Intermediate position
            printf("Enter item where u want to delete: ");
            scanf("%d", &pos);
            current = first;
            while (current->data != pos)
            {
                current = current->rlink;
            }
            current->llink->rlink = current->rlink;
            current->rlink->llink = current->llink;
            break;

        case 8: // Display Forward
            current = first;
            if (first == NULL)
            {
                printf("Linked list is empty!");
            }
            else
            {
                while (current != NULL)
                {
                    printf("%d\t", current->data);
                    current = current->rlink;
                }
            }
            printf("\n");
            break;

        case 9: // Display Backward
            current = last;
            if (first == NULL)
            {
                printf("Linked list is empty!");
            }
            else
            {
                while (current != NULL)
                {
                    printf("%d\t", current->data);
                    current = current->llink;
                }
            }
            printf("\n");
            break;
        }
        printf("Enter 0 if u want to repeat again: ");
        scanf("%d", &con);
    } while (con == 0);
}