#include <iostream.h>
#include <conio.h>
#include <stdio.h>

class Stack
{
public:
	int top;
	int a[5];

	Stack()
	{
		top = -1;
	}

	void push()
	{
		if (top == 5)
		{
			cout << "Stack is Full...!" << endl;
		}
		else
		{
			int val;
			if (top == -1)
			{
				cout << "Enter Elemnt to insert into stack... ";
				cin >> val;
				top = 0;
				a[top] = val;
				cout << "The element " << a[top] << " is inseted into stack...!" << endl;
			}
			else
			{
				cout << "Enter Elemnt to insert into stack... ";
				cin >> val;
				top++;
				a[top] = val;
				cout << "The element " << a[top] << " is inseted into stack...!" << endl;
				cout << top << endl;
			}
		}
	}

	void pop()
	{
		if (top == -1)
		{
			cout << "Stack is empty...!" << endl;
		}
		else
		{
			int val = a[top];
			cout << "The element " << val << " is removed from stack...!" << endl;
			if (top != 0)
			{
				top--;
			}
			else
			{
				top = -1;
			}
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
				cout << a[i] << "\t";
			}
			cout << endl;
		}
	}
};

int main()
{
	clrscr();
	Stack stack;
	int opration;
	int exit;

	do
	{
		cout << "Enter the number along with the operation " << endl;
		cout << "1)PUSH \n2)POP \n3) Print" << endl;
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