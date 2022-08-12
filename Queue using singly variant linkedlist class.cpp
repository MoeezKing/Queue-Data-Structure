#include <iostream>
using namespace std;
class Node
{
    int data;
    Node* next;
public:
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node* next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    Node* getNext()
    {
        return next;
    }
    Node(int data = 0, Node* next = NULL)
    {
        setData(data);
        setNext(next);
    }
};
class LinkedList
{
    Node* head;
    Node* last;
public:
    void setHead(Node* head)
    {
        this->head = head;
    }
    void setLast(Node* last)
    {
        this->last = last;
    }
    Node* getHead()
    {
        return head;
    }
    Node* getLast()
    {
        return last;
    }
    LinkedList(Node* head = NULL, Node* last = NULL)
    {
        setHead(head);
        setLast(last);
    }
    bool isEmpty()
    {
        if (head == NULL && last == NULL)
            return true;
        else
            return false;
    }
    int getLenght()
    {
        int lenght = 0;
        Node* temp = head;
        while (temp != NULL)
        {
            lenght++;
            temp = temp->getNext();
        }
        return lenght;
    }
    void insertFromBeginning(int val)
    {
        Node* temp = new Node(val);
        temp->setNext(head);
        head = temp;
        if (last == NULL)
            last = temp;
    }
    void insertFromLast(int val)
    {
        Node* temp = new Node(val);
        if (isEmpty())
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->setNext(temp);
            last = temp;
        }
    }
    bool removeFromBeginning()
    {
        if (isEmpty())
            return false;
        else
        {
            int lenght = getLenght();
            Node* temp = head->getNext();
            if (lenght != 1)
            {
                delete head;
                head = temp;
                return true;
            }
            else
            {
                delete head;
                head = temp;
                last = head;
                return true;
            }
        }
    }
    bool removeFromLast()
    {
        if (isEmpty())
            return false;

        int lenght = getLenght();
        if (lenght == 1)
        {
            delete head;
            head = NULL;
            last = NULL;
            return true;
        }

        delete last;
        Node* temp = head;
        for (int i = 1; i < lenght - 1; i++)
            temp = temp->getNext();
        temp->setNext(NULL);
        last = temp;
        return true;
    }
    int getFirstElement()
    {
        if (isEmpty())
            return NULL;
        else
            return head->getData();
    }
    int getLastElement()
    {
        if (isEmpty())
            return NULL;
        else
            return last->getData();
    }
    void print()
    {
        cout << endl;
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
};
class Queue
{
    LinkedList l1;
    int size;
public:
    int getSize()
    {
        return size;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    Queue(int size = 15)
    {
        setSize(size);
    }
    bool isEmpty()
    {
        return (l1.isEmpty()) ? true : false;
    }
    bool  isFull()
    {
        int lenght = l1.getLenght();
        return (lenght == size) ? true : false;
    }
    bool enqueue(int val)
    {
        if (!(isFull()))
        {
            l1.insertFromBeginning(val);
            return true;
        }
        else
        {
            cout << "\nQueue is FULL.";
            return false;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty.";
            return NULL;
        }
        else
        {
            int data = l1.getLastElement();
            l1.removeFromLast();
            return data;
        }
    }
    int getPeek()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty . So,Peek is NULL(0)";
            return NULL;
        }
        return l1.getLastElement();
    }
    void printQueue()
    {
        cout << "\nPrinting all the elements of Queue.\n";
        l1.print();
    }
};
int main()
{
    Queue q1;

    for (int i = 0; i < 15; i++)
        q1.enqueue(i + 1);

    cout << "\nSize of Queue is " << q1.getSize();

    if (q1.isFull())
    {
        cout << "\nQueue is full.";
    }
    else
    {
        cout << "\nQueue is not full yet.";
    }

    q1.enqueue(20);

    q1.printQueue();

    int sum = 0;
    for (int i = 1; i < 16; i++)
        sum = sum + q1.dequeue();

    int i = q1.dequeue();

    cout << "\npeek element is " << q1.getPeek();
    cout << "\nSum of all the elements in Queue is " << sum;
    return 0;
}
