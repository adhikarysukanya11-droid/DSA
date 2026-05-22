#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

// Push string into stack
void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

// Pop string from stack
char* pop()
{
    return stack[top--];
}

// Check operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Priority function
int priority(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// INFIX TO POSTFIX
void infixToPostfix(char infix[])
{
    char stack1[100];
    int top1 = -1;
    int i;
    char ch;

    printf("Postfix Expression: ");

    for(i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            printf("%c", ch);
        }
        else if(ch == '(')
        {
            stack1[++top1] = ch;
        }
        else if(ch == ')')
        {
            while(stack1[top1] != '(')
            {
                printf("%c", stack1[top1--]);
            }
            top1--;
        }
        else
        {
            while(top1 != -1 && priority(stack1[top1]) >= priority(ch))
            {
                printf("%c", stack1[top1--]);
            }

            stack1[++top1] = ch;
        }
    }

    while(top1 != -1)
    {
        printf("%c", stack1[top1--]);
    }

    printf("\n");
}

// POSTFIX TO INFIX
void postfixToInfix(char postfix[])
{
    int i;
    char ch;
    char op1[100], op2[100], temp[100];

    top = -1;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if(isalnum(ch))
        {
            temp[0] = ch;
            temp[1] = '\0';

            push(temp);
        }
        else if(isOperator(ch))
        {
            strcpy(op2, pop());
            strcpy(op1, pop());

            sprintf(temp, "(%s%c%s)", op1, ch, op2);

            push(temp);
        }
    }

    printf("Infix Expression: %s\n", pop());
}

// PREFIX TO INFIX
void prefixToInfix(char prefix[])
{
    int i;
    char ch;
    char op1[100], op2[100], temp[100];

    top = -1;

    for(i = strlen(prefix)-1; i >= 0; i--)
    {
        ch = prefix[i];

        if(isalnum(ch))
        {
            temp[0] = ch;
            temp[1] = '\0';

            push(temp);
        }
        else if(isOperator(ch))
        {
            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(temp, "(%s%c%s)", op1, ch, op2);

            push(temp);
        }
    }

    printf("Infix Expression: %s\n", pop());
}

// MAIN FUNCTION
int main()
{
    int choice;
    char exp[100];

    while(1)
    {
        printf("\n--- EXPRESSION CONVERSION MENU ---\n");
        printf("1. Infix to Postfix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Prefix to Infix\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", exp);

                infixToPostfix(exp);
                break;

            case 2:
                printf("Enter Postfix Expression: ");
                scanf("%s", exp);

                postfixToInfix(exp);
                break;

            case 3:
                printf("Enter Prefix Expression: ");
                scanf("%s", exp);

                prefixToInfix(exp);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}