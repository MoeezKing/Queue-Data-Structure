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
public:
	void setHead(Node* head)
	{
		this->head = head;
	}
	Node* getHead()
	{
		return head;
	}
	LinkedList(Node* head = NULL)
	{
		setHead(head);
	}
	bool isEmpty()
	{
		return (head == NULL) ? true : false;
	}
	void insertAtBeginning(int data)
	{
		if (isEmpty())
		{
			Node* t = new Node(data);
			head = t;
		}
		else
		{
			Node* t = new Node(data);
			t->setNext(head);
			head = t;
		}
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
	bool removeFromLast()
	{
		if (isEmpty())
		{
			return false;
		}
		else
		{
			int lenght = getLenght();
			if (lenght == 1)
			{
				delete head;
				head = NULL;
				return true;
			}
			
			Node* temp = head;
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
			}
			delete temp;
			temp = head;
			for (int i = 0; i < lenght - 2; i++)
			{
				temp = temp->getNext();
			}
			temp->setNext(NULL);
			return true;
		}
	}
	
	int getLastElement()
	{
		if (isEmpty())
			return NULL;

		Node* last = head;
		while (last->getNext() != NULL)
		{
			last = last->getNext();
		}
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
		return (lenght == size) ? true: false;
	}
	bool enqueue(int val)
	{
		if (!(isFull()))
		{
			l1.insertAtBeginning(val);
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
		q1.enqueue(i+1);

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
