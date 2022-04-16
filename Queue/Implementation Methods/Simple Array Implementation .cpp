/* Queue 
	
	Simple Array Implementation (Circular Array) 

*/

#include<iostream>
using namespace std;
class Queue
{
	int front, rear, capacity;
	int size;
	int* arr;
public:
	Queue(int n)
	{
		front = rear = -1;
		size = 0;
		capacity = n;
		arr = (int*)malloc(capacity * sizeof(int));
	}
	bool isFull()
	{
		return((rear + 1) % capacity == front);
	}
	bool isEmpty()
	{
		return front == -1;
	}

	/* Insert Element to the Queue */

	void EnQueue(int data)
	{
		if (isFull())
		{
			cout << "Queue is Full \n";
			return;
		}
		rear = (rear + 1) % capacity;
		arr[rear] = data;
		if (front == -1)
			front = rear;
		size++;
	}

	/* Remove The First Element from the Queue */
	void DeQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % capacity;
		size--;
	}

	/* Get the Front Element From the Queue */
	void getfront()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		cout << "Front Element is : " << arr[front] << endl;
	}
	/* Get the Rear Element from the Queue */
	void getrear()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		cout << "The rear Element is : " << arr[rear] << endl;
	}

	/* Print the Elements of the Queue */
	void print()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		for (int i = front; i != rear; i = (i + 1) % capacity)
		{
			cout << arr[i] << "\t";
		}
		cout << arr[rear] << endl;
	}
};
int main()
{
	Queue q(5);
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.EnQueue(5);
	q.print();
	q.DeQueue();
	q.print();
	q.getfront();
	q.getrear();
}