#include <iostream>
using namespace std;

template<class T>
class Queue
{
public:
	int front;
	int rear;
	int capacity;
	T * array;

	Queue(int _size): capacity(_size), front(-1), rear(-1)
	{
		array = new T[_size];
	}

	void enqueue(T data)
	{
		rear = (rear+1)%capacity;
		array[rear] = data;
		
		if(front == -1 )
			front = rear;
	}

	T dequeue()
	{
		T data = array[front];
		front = (front+1)%capacity;

		return data;
	}
};

int main()
{
	Queue<int> aQueue(10);
	aQueue.enqueue(6);
	aQueue.enqueue(5);
	aQueue.enqueue(4);

	cout << aQueue.dequeue() << endl;
	aQueue.enqueue(3);
	aQueue.enqueue(2);
	aQueue.enqueue(1);

	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
	cout << aQueue.dequeue() << endl;
}

