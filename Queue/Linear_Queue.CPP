#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

#define MAX 5

class LinearQueue
{
private:
    int front, rear;
    int queue[MAX];

public:
    LinearQueue()
    {
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow!" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            queue[++rear] = value;
            cout << "Inserted " << value << " into the queue." << endl;
        }
    }

    void remove()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;
        }
        else
        {
            cout << "Removed " << queue[front++] << " from the queue." << endl;
            if (front > rear)
            {
                front = rear = -1;
            }
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    LinearQueue q;
    int get, get2, data;
    cout << "Do not enter the charecter input...! \nThe loop gose in infinite mode...!!!!!!!!!!!!!" << endl;
    do
    {
        cout << endl
             << "Enter the number along with the operation :- " << endl;
        cout << "1) Insert \n2) Delete \n3) Desplay" << endl;
        cin >> get;
        switch (get)
        {
        case 1:
            cout << "Enter the number to insert in queue" << endl;
            cin >> data;
            q.insert(data);
            break;
        case 2:
            q.remove();
            break;
        case 3:
            q.display();
            break;
        default:
            cout << "Enter valid option...!" << endl;
            break;
        }
        cout << "Do you wont to continue...??" << endl;
        cout << "1) Yes \n2) No" << endl;
        cin >> get2;
        switch (get2)
        {
        case 1:
            continue;
        case 2:
            break;
        default:
            cout << "Enter Again...!!" << endl;
            cin >> get2;
        }
    } while (get2 == 1);
    return 0;
}
