#include <stdio.h>
#include <string.h>

#define MAX 100

char Stack[MAX];
int f;

int IsFull(void)
{
    if (f == MAX-1) {
        printf("Stack is FULL..\n");
        return 1;
    }
    else
        return 0;
}

int IsStackEmpty(void)
{
    if (f == -1) {
        printf("Stack is Empty..\n");
        return 1;
    }
    else
        return 0;
}

char peek(void)
{
    return Stack[f];

}

char pop(void)
{
    if (IsStackEmpty()) {
        return -1;
    } else {
        char element = Stack[f];
        f--;
        return element;
    }
}

void push(char element)
{
    if (IsFull()) {
        return;
    } else {
        Stack[++f] = element;
    }
}

int IsClosingBracket(char ch)
{
    if (ch == ')')
        return 1;
    else
        return 0;
}

int IsOpeningBracket(char ch)
{
    if (ch == '(')
        return 1;
    else
        return 0;
}


int IsOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') /*|| ch >= '0' || ch <= '9'*/)
        return 1;
    else
        return 0;
}

int Precedence(char ch)
{
    switch(ch) {
        case '-' :
            return 1;
        case '+' :
            return 2;
        case '*' :
            return 3;
        case '/' :
            return 4;
        default:
            return 0;
    }
}

void infix_to_post_routine(char *infix, char *postfix)
{
    int k, l;

    for(k=0, l=0; infix[k] != '\0'; k++) {

        if (IsClosingBracket(infix[k])) {

            /* Check till u find the opening brace inside stack */
            while (!IsStackEmpty() && (peek() != '(')) {
                postfix[l] = pop();
                printf("postfixchar[%c] l [%d]\n", postfix[l], l);
                l++;
            }
            pop(); //just pop the opening brace out of the stack

        } else if (IsOpeningBracket(infix[k])) {
            push(infix[k]);

        } else if(IsOperand(infix[k])) {

            postfix[l] = infix[k];
            printf("postfixchar[%c] l [%d]\n", postfix[l], l);
            l++;

        } else { /* Operator */

            /* If stack is already empty, simply push the operator */
            if (IsStackEmpty() || (Precedence(infix[k])> Precedence(peek()))) {

                push(infix[k]);

            } else  { /* Stack is not empty, just check the precedence */
                while(!IsStackEmpty() && (Precedence(peek()) >= Precedence(infix[k]))) {
                    char ch = pop();
                    if (ch == '(' || ch == ')') {
                        //printf("oper: char [%c]\n", infix[k]);
                    } else {
                        postfix[l] = ch;
                        printf("postfixchar[%c] l [%d]\n", postfix[l], l);
                        l++;
                    }
                }
                push(infix[k]); //If precedence is greater than precesence of the stack top operator, then simply push
            }

        }
    }
    while(!IsStackEmpty()) {
        postfix[l] = pop();
        l++;
    }
    postfix[l] = '\0';
}


int main(void)
{
    char infix[MAX], postfix[MAX];
    f = -1;

    printf("Welcome to Infix to PostFix conversion algorithm....\n");
    printf("Enter the infix expression string...\n");
    scanf("%s", &infix);

    printf("The original infix expression is [%s]", infix);

    infix_to_post_routine(infix, postfix);
    printf("The postfix expression is [%s]", postfix);
}

