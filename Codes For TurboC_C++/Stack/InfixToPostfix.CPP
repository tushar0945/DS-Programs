#include <iostream.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>

const int MAX = 100;

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
			cout << "Stack is empty \n"
				 << endl;
			return '\0';
		}
		return stack[top];
	}

	int inEmpty()
	{
		return (top < 0);
	}
};

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
//@_tushar__45._;
int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
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
			while (!cstack.inEmpty() && cstack.peek() != '(')
			{
				postfix[j++] = cstack.pop();
			}
			cstack.pop();
		}
		else if (isOperator(c))
		{
			while (!cstack.inEmpty() && opPrecedence(cstack.peek()) > opPrecedence(c))
			{
				postfix[j++] = cstack.pop();
			}
			cstack.push(c);
		}
	}

	while (!cstack.inEmpty())
	{
		postfix[j++] = cstack.pop();
	}
	postfix[j] = '\0';
}

int main()
{
	clrscr();
	char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-1";
	char postfix[MAX];

	infixToPostfix(infix, postfix);

	cout << "Infix : " << infix << endl;
	cout << "Postfix : " << postfix << endl;

	getch();
	return 0;
}