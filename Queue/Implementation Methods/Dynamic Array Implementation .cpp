#include<iostream>
using namespace std;
class Queue
{
	int front, rear;
	int capacity;
	int* arr;
public:
	Queue()
	{
		front = rear = -1;
		capacity = 1;
		arr = new int[capacity];
	}
	bool isFull()
	{
		return ((rear + 1) % capacity == front);
	}
	bool isEmpty()
	{
		return (front == -1); 
	}

	// resize the Array 
	void resize()
	{
		const int size = capacity;
		capacity *= 2;
		int* m = new int;
		if (arr)
		{
			m = (int*)realloc(arr, capacity * sizeof(int));
			if (m)
				arr = m;
		}

		if (!arr)
		{
			cout << "Memory Error !!\n";
			return;
		}

		if (front > rear)
		{
			for (int i = 0; i < front; i++)
			{
				arr[i + size] = arr[i];
			}
			rear += size;
		}
	}

	void EnQueue(int data)
	{
		if (!arr)
		{
			cout << "Queue has been Deleted \n";
			return;
		}

		if (isFull())
			resize();
		rear = (rear + 1) % capacity;
		arr[rear] = data;
		if (front == -1)
			front = rear;
	}
	void DeQueue()
	{
		if (!arr)
		{
			cout << "Queue has been Deleted \n";
			return;
		}

		if (isEmpty())
		{
			cout << "Queue is Empty \n";
			return;
		}
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % capacity;
		}
	}

	void print()
	{
		if (!arr)
		{
			cout << "Queue has been Deleted \n";
			return;
		}

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
	// Delete All the Elements from the Queue

	void DeleteQueue()
	{
		delete arr;
		arr = nullptr;
	}
};
int main()
{
	Queue q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);

	q.print();
	q.DeQueue();
	q.print();
	q.DeleteQueue();
	q.EnQueue(1);
	q = Queue();
	q.EnQueue(10);
	q.EnQueue(20);
	q.print();

	Queue Q;
	Q.EnQueue(5);
	Q.EnQueue(6);
	Q.EnQueue(7);
	Q.EnQueue(8);
	Q.DeQueue();
	Q.EnQueue(100);
	Q.print();

}