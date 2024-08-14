#include <iostream>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;
#define MAX 100

class CharStack
{
private:
    int top;
    char stack[MAX];

public:
    CharStack() { top = -1; }

    void push(char c)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = c;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return stack[top--];
    }

    char peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return stack[top];
    }

    int isEmpty()
    {
        return (top < 0);
    }
};
//@_tushar__45._;
int opPrecedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void reverseString(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPostfix(const char infix[], char postfix[])
{
    CharStack cstack;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            cstack.push(c);
        }
        else if (c == ')')
        {
            while (!cstack.isEmpty() && cstack.peek() != '(')
            {
                postfix[j++] = cstack.pop();
            }
            cstack.pop();
        }
        else if (isOperator(c))
        {
            while (!cstack.isEmpty() && opPrecedence(cstack.peek()) > opPrecedence(c))
            {
                postfix[j++] = cstack.pop();
            }
            cstack.push(c);
        }
    }

    while (!cstack.isEmpty())
    {
        postfix[j++] = cstack.pop();
    }
    postfix[j] = '\0';
}

void infixToPrefix(const char infix[], char prefix[])
{
    int n = strlen(infix);

    char revInfix[MAX];
    strcpy(revInfix, infix);
    reverseString(revInfix);

    for (int i = 0; i < n; i++)
    {
        if (revInfix[i] == '(')
        {
            revInfix[i] = ')';
        }
        else if (revInfix[i] == ')')
        {
            revInfix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(revInfix, postfix);

    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main()
{

    char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-1";
    char prefix[MAX];

    infixToPrefix(infix, prefix);

    cout << "Infix : " << infix << endl;
    cout << "Prefix : " << prefix << endl;

    getch();
    return 0;
}
