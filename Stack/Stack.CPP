#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
const int MAX = 100;

class Stack
{
public:
	int top;
	int stack[MAX];

	Stack()
	{
		top = -1;
	}

	void push()
	{
		if (top >= MAX - 1)
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		else
		{
			int val;
			cout << "Enter Elemnt to insert into stack... ";
			cin >> val;
			stack[++top] = val;
			cout << "The element " << stack[top] << " is inseted into stack...!" << endl;
		}
	}

	void pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow" << endl;
			return;
		}
		else
		{
			int val = stack[top--];
			cout << "The element " << val << " is removed from stack...!" << endl;
		}
	}

	void peek()
	{
		if (top < 0)
		{
			cout << "Stack is empty " << endl;
			return;
		}
		else
		{
			int val = stack[top];
			cout << "The peek value is " << val << endl;
		}
	}

	void print()
	{
		if (top == -1)
		{
			cout << "Stack is empty...!" << endl;
		}
		else
		{
			cout << "Ements stored in stack " << endl;
			for (int i = 0; i <= top; i++)
			{
				cout << stack[i] << "\t";
			}
			cout << endl;
		}
	}
};

int main()
{
	Stack stack;
	int opration;
	int exit;

	do
	{
		cout << "Enter the number along with the operation " << endl;
		cout << "1)PUSH \n2)POP \n3)Peek \n4) Print" << endl;
		cin >> opration;

		switch (opration)
		{
		case 1:
			stack.push();
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			stack.peek();
			break;
		case 4:
			stack.print();
			break;
		default:
			cout << "Enter valid number...!" << endl;
			break;
		}
		cout << "Do you wont to continue...!" << endl;
		cout << "1) Yes \n2) No" << endl;
		cin >> exit;
	} while (exit == 1);
	return 0;
}