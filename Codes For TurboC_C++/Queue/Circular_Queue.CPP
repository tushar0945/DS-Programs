#include <iostream.h>
#include <stdio.h>
#include <conio.h>

#define ture = 1;
#define flase = 0;

#define MAX 5

class CircularQueue
{
private:
    int front, rear;
    int queue[MAX];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void insert(int value)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Queue Overflow!" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            queue[rear] = value;
            cout << "Inserted " << value << " into the queue." << endl;
        }
    }

    //@_tushar__45._

    void remove()
    {
        if (front == -1)
        {
            cout << "Queue Underflow!" << endl;
        }
        else
        {
            cout << "Removed " << queue[front] << " from the queue." << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
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
            int i = front;
            while (1)
            {
                cout << queue[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
    }
};

int main()
{
    clrscr();
    CircularQueue q;

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
