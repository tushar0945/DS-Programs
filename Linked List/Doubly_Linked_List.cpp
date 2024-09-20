#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    void create()
    {
        head = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newHead = new Node(val);
        if (head != NULL)
        {
            head->prev = newHead;
        }
        newHead->next = head;
        head = newHead;
    }

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
        newNode->prev = temp;
    }

    //@_tushar__45._

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
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    //@_tushar__45._

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *toDelete = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete toDelete;
    }

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
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

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
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
        delete toDelete;
    }

    //@_tushar__45._

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
        while (temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Value not found in the list" << endl;
            return;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

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

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int get, get2, data;
    cout << "Do not enter character input...! \nThe loop goes in infinite mode...!!!!!!!!!!!!!" << endl;
    do
    {
        cout << endl
             << "Enter the number along with the operation :- " << endl;
        cout << "1) InsertAtHead \n2) InsertAtPosition \n3) InsertAtTail \n4) deleteAtHead \n5) DeleteAtPosition \n6) deleteAtTail \n7) Display \n8) Find \n9) Display Reverse" << endl;
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
            cout << "Specify the position to insert element" << endl;
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
            break;
        case 9:
            list.displayReverse();
            break;
        default:
            cout << "Enter valid option...!" << endl;
            break;
        }
        cout << "Do you want to continue...??" << endl;
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
