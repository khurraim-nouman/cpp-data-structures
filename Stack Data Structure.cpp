#include <iostream>

using namespace std;

class Stack 
{
	private:
		int top;
		int arr[5];
		
	public:
		
		// Constructor (Initializes all value in stack to zero)
		Stack()
		{
			top = -1;
			for(int i = 0; i < 5; i++)
			{	
				arr[i] = 0;
			}
		}
		
		
		// Method : Check if the stack is empty
		bool isEmpty()
		{
			if (top == -1)
			{
				return true;
			} else {
				return false;
			}
		}
		
		
		// Method : Check if the stack is full
		bool isFull()
		{
			if(top == 4)
			{
				return true;
			} else {
				return false;
			}
			
		}
		
		
		// Method: Push value in a stack 
		void push(int val)
		{
			if(isFull())	
			{
				cout << " Stack Overflow " << endl;
			}
			else
			{
				top++;
				arr[top] = val;
			}
		}
		
		
		
		
		
		// Method: Get value from the stack
		int pop()
		{
			if(isEmpty())
			{
				cout << " Stack Underflow " << endl;
				return 0;
			}
			else
			{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
			}
		}
		
		
		
		
		// Method: Count the stack
		int count()
		{
			return (top + 1);
		}
		
		
		
		
		// Method: Getting Value from the position
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout << " Stack Underflow " << endl;
				return 0;
			}
			else
			{
				return arr[pos];
			}
		}
		
		
		
		// Method: Change the value at the stack
		void change(int pos, int val)
		{
			arr[pos] = val;
			cout << "Item Changed At Position " << pos << endl;
		}
		
		
		// Method: Display values in the stack
		void display()
		{
			cout << "All Values in the stack are : " << endl;
			for(int i = 4; i >= 0; i--)
			{
				cout << arr[i] << endl;
			}
		}
		
		
		
			
};

int main()
{
	Stack s1;
	int option, position, value;
	
	do
	{
		cout << "Which Operation Do You Want To Perform? Select Option Number. Enter 0 to Exit. " << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. pook()" << endl;
		cout << "6. count()" << endl;
		cout << "7. change()" << endl;
		cout << "8. display()" << endl;
		cout << "9. Clear Screen" << endl;
		
		
		cin >> option;
		switch(option)
		{
			case 1:
				cout << "Enter an item to push in the stack " << endl;
				cin >> value;
				s1.push(value);
				break;
				
			case 2:
				cout << "Pop Function Called -\n Popped Value: " << s1.pop() << endl;
				break;
				
			case 3: 
				if(s1.isEmpty())	
					cout << "Stack Is Empty" << endl;
				else	
					cout << "Stack Is Not Empty " << endl;
				break;	
				
				
			case 4:
				if(s1.isFull())	
					cout << "Stack Is Full" << endl;
				else
					cout << "Stack Is Not Full"	 << endl;
				break;	
				
				
				
			case 5:
				cout << "Enter position of item you want to peek: "	<< endl;
				cin >> position;
				cout << "Peeked Function Called - Value : " << s1.peek(position) << endl;
				break;	
			
			case 6:
				cout << "Count Function Called - The number of items in the stack are: " << s1.count() << endl;
				break;
				
			case 7:
			 	cout << "Change Function Called  - " << endl;
			 	cout << "Enter the position you want to change : ";
			 	cin >> position;
			 	cout << endl;
			 	cout << "Enter the value you want to change : ";
			 	cin >> value;
			 	s1.change(position, value);
			 	break;
			 	
			case 8:
				cout << "Display Function Called : " << endl;
				s1.display();
				break;
				
			case 9:
				system("cls");	
				break;
				
			default:
				cout << "Enter Proper Option Number " << endl;
				
		}
		
	} while(option != 0);
	
	return 0;
	
}
