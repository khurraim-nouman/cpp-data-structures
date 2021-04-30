#include <iostream>
using namespace std;

class Queue 
{
	private:
		int front;
		int rear;
		int arr[5];
		
		
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			
			for(int i = 0; i < 5; i++)
			{
				arr[i] = 0;
			}
			
		}
		
		bool isEmpty()
		{
			if(front == -1 && rear == -1)
				return true;
			else
				return false;		
		}
		
		bool isFull()
		{
			if(rear == 4)
				return true;
			else 
				return false;	
		}
		
		void enqueue (int val)
		{
			if(isFull())
			{
				cout << "Queue Is Full. " << endl;
			}
			else if(isEmpty())
			{
				rear = 0;
				front = 0;
				arr[rear] = val;
			}
			else
			{
				rear++;
				arr[rear] = val;
			}
		}
		
		int dequeue()
		{
			
		}
		
		
};

int main()
{
	
}
