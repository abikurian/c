#include <stdio.h>
#define num 20 // Increased stack size for clarity
char stk[num];
char ex[25], post[25];
int top = -1, cont;

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1; // Return -1 for non-operators
    }
}

char pop()
{
    if (top == -1)
    {
        return -1; // Return -1 if stack is empty
    }
    char ch = stk[top];
    top--;
    return ch;
}

void push(char oper)
{
    if (top >= (num - 1))
    {
        printf("STACK IS FULL\n");
    }
    else
    {
        top++;
        stk[top] = oper;
    }
}

int ifoperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void convert()
{
    int i, j = 0; // Initialize j to 0
    for (i = 0; ex[i] != '\0'; i++)
    {
        if (ifoperand(ex[i]))
        {
            post[j++] = ex[i]; // Add operand to post and increment j
        }
        else if (ex[i] == '[')
        {
            push(ex[i]);
        }
        else if (ex[i] == ']')
        {
            while (top != -1 && stk[top] != '[')
            {
                post[j++] = pop(); // Pop until '['
            }
            pop(); // Pop the '['
        }
        else
        {
            while (top != -1 && precedence(stk[top]) >= precedence(ex[i]))
            {
                post[j++] = pop(); // Pop while precedence is higher or equal
            }
            push(ex[i]); // Push the current operator
        }
    }
    // Pop all remaining operators from the stack
    while (top != -1)
    {
        post[j++] = pop();
    }
    post[j] = '\0'; // Null terminate the postfix expression
}

int main()
{ // Changed to return int
    do
    {
        printf("Enter an infix expression: ");
        scanf("%s", ex);
        convert();
        printf("Postfix expression: %s\n", post);
        printf("Print 1 to continue: ");
        scanf("%d", &cont); // Corrected format specifier
    } while (cont == 1);

    return 0; // Return success
}