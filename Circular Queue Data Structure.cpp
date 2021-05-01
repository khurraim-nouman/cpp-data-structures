#include <iostream>
using namespace std;

class CircularQueue 
{
	private:
		int front;
		int rear;
		int arr[5];
		
		
	public:
		CircularQueue()
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
			if(rear+1%5 == front)
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
				rear = (rear+1) % 5;
				arr[rear] = val;
			}
		}
		
		int dequeue()
		{
			int x;
			if(isEmpty())
			{	
				cout << "Queue Is Empty " << endl;
				return x;
			}
			else if(rear == front)
			{
				x = arr[rear];
				rear = -1;
				front = -1;
				return x;
			}
			else
			{
				cout << "Front Value : " << front << endl;
				x = arr[front];
				arr[front] = 0;
				front++;
				return x;
			}
			
		}
		
		int count()
		{
			return (rear - front + 1);
		}
		
		void display()
		{
			cout << "All the values in the Queue are : " << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << arr[i] << "  ";
			}
		}
		
		
};

int main()
{
	CircularQueue q1;
	int option, value;
	
	do
	{
		cout << "\n \n Which Operation Do You Want To Perform? Select Option Number. Enter 0 To Exit. " << endl;
		cout << "1. Enqueue() " << endl;
		cout << "2. Dequeue() " << endl;
		cout << "3. isEmpty() " << endl;
		cout << "4. isFull() " << endl;
		cout << "5. count() " << endl;
		cout << "6. display() " << endl;
		cout << "7. Clear Screen  " << endl << endl;
		
		cin >> option;
		
		switch(option)
		{
			case 0:
				break;
				
			case 1:
				cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue " << endl;
				cin >> value;
				q1.enqueue(value);
				break;
				
			case 2:
				cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
				break;
				
			case 3:
				if (q1.isEmpty())
					cout << "Queue is Empty " << endl;
				else
					cout << "Queue is not Empty " << endl;
				break;
				
			case 4:
				if (q1.isFull())
					cout << "Queue is Full " << endl;
				else
					cout << "Queue is not Full " << endl;
				break;				
				
				
			case 5:
				cout << "Count Operation. \n Count Of items in Queue " << q1.count() << endl;
				break;
				
			case 6:
				cout << "Display Function Called - " << endl;
				q1.display();
				break;
				
			case 7:
				system("cls");
				break;	
				
			default:
				cout << "Enter Proper Number "	<< endl;
				break;
		}
		
	} while (option != 0);
}
