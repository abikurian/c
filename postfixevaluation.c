#include <stdio.h>
#include <ctype.h>
#define size 50
int s[size], top = -1, v;
char p[50], ch;
int i = 0, op1, op2;
void push(int elem)
{
    s[++top] = elem;
}
int pop()
{
    return s[top--];
}
int main()
{
    printf("Enter the postfix expression: ");
    scanf("%s", p);
    while ((ch = p[i++]) != '\0')
    {
        if (isalpha(ch))
        {
            printf("Enter the value: ");
            scanf("%d", &v);
            push(v);
        }
        else
        {
            op1 = pop();
            op2 = pop();
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op2 * op1);
                break;

            case '/':
                push(op2 / op1);
                break;
            }
        }
    }
    printf("Given postfix expression is: %s\n", p);
    printf("The result is: %d\n", s[top]);
    return 0;
}