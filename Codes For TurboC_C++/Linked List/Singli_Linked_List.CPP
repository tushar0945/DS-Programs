#include <iostream.h>
#include <stdio.h>
#include <conio.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    // Create an empty list
    void create()
    {
        head = NULL;
    }

    // Insert a node at the head
    void insertAtHead(int val)
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
    }

    // Insert a node at the tail
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a node at a specific position (1-based index)
    void insertAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            insertAtHead(val);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //@_tushar__45._

    // Delete the head node
    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Delete the last node
    void deleteAtTail()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    // Delete a node at a specific position (1-based index)
    void deleteAtPosition(int pos)
    {
        if (pos == 1)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete a node with a specific value
    void deleteNode(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val)
        {
            deleteAtHead();
            return;
        }

        Node *temp = head;
        while (temp->next != NULL && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Find a node with a specific value
    int find(int val)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }

    // Display the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    clrscr();
    LinkedList list;
    int get, get2, data;
    cout << "Do not enter the charecter input...! \nThe loop gose in infinite mode...!!!!!!!!!!!!!" << endl;
    do
    {
        cout << endl
             << "Enter the number along with the operation :- " << endl;
        cout << "1) InsertAtHead \n2) InsertAtPosition \n3) InsertAtTail \n4) deleteAtHead \n5) DeleteAtPosition \n6) deleteAtTail \n7) Display \n8) Find" << endl;
        cin >> get;
        switch (get)
        {
        case 1:
            cout << "Enter the number to insert at head in Linked List" << endl;
            cin >> data;
            list.insertAtHead(data);
            break;
        case 2:
            int position;
            cout << "Specify the position to insrt element" << endl;
            cin >> position;
            cout << "Enter the number to insert at specified position in Linked List" << endl;
            cin >> data;
            list.insertAtPosition(data, position);
            break;

        case 3:
            cout << "Enter the number to insert at tail in Linked List" << endl;
            cin >> data;
            list.insertAtTail(data);
            break;

        case 4:
            list.deleteAtHead();
            break;

        case 5:
            cout << "Specify the position to delete the element" << endl;
            cin >> position;
            list.deleteAtPosition(position);
            break;

        case 6:
            list.deleteAtTail();
            break;
        case 7:
            list.display();
            break;

        case 8:
            cout << "Specify element to find in Linked List" << endl;
            cin >> data;

            if (list.find(data))
            {
                cout << data << " found in the list" << endl;
            }
            else
            {
                cout << data << " not found in the list" << endl;
            }
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
