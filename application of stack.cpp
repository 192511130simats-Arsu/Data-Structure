#include <stdio.h>
#include <ctype.h>  // for isalpha() and isdigit()
#define SIZE 100

char stack[SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1)
        return -1; // return -1 if stack is empty
    else
        return stack[top--];
}

// Function to define operator precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[]) {
    char *e, x;
    printf("Postfix Expression: ");
    e = infix;

    while (*e != '\0') {
        if (isalnum(*e))  // if operand, print directly
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {  // operator
            while (precedence(stack[top]) >= precedence(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }

    // Pop remaining operators
    while (top != -1)
        printf("%c", pop());

    printf("\n");
}

int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
