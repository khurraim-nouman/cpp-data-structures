#include <iostream>

using namespace std;

// Class For Node 
class Node 
{		
	public:
		
		int key;		// Key : Unique Identifier 
		int data;		// Data : Value Node Holds
		Node* next;		// Next : Address of next Node
		
		
		// Normal Constructor ( Initializes All Value To Zero )
		Node()
		{
			key = 0;
			data = 0;
			next = NULL;
		}
		
		// Parameterized Constructor ( Sets Node with key and data as parameters )
		Node(int k, int d)
		{
			key = k;
			data = d;
			next = NULL;
		}
			
};

// Class For Linked List ( Address Holding )
class SinglyLinkedList
{
	public:
		
		Node* head;
		
		// Normal Constructor ( Head Starts With Zero )
		SinglyLinkedList()
		{
			head = NULL;
		}
		
		
		// Parameterized Constructor ( New Node Prepend , So We change Head )
		SinglyLinkedList(Node* n)
		{
			head = n;
		}
		
		// Method: Check if the node exists ( using key value )
		Node* nodeExists(int k)
		{
			Node* temp = NULL;
			Node* ptr = head;
			
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr = ptr -> next;
			}
			
			return temp;
		}
		
		// Method: Append a node to the list
		void appendNode(Node *n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout << "Node already exists with key value : " << n->key << ". Append another node with different key value. " << endl;
			}
			else 
			{
				if(head==NULL)
				{
					head = n;
					cout << "Node appended. " << endl;
				}
				else
				{
					Node* ptr = head;
					while(ptr->next!=NULL)
					{
						ptr = ptr->next;
					}
					ptr->next=n;
					cout << "Node Appended. " << endl;
				}
			}
		}
		
		// Method: Prepend A Node ( Attach a Node To The Start )
		void prependNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout << "Node already exists with key value : " << n->key << ". Append another node with different key value. " << endl;
			}
			else 
			{
				n->next = head;
				head = n;
				cout << "Node prepended ." << endl;
			}
		}
		
		// Method: Insert A Node After Particular Node In The List 
		void insertNodeAfter(int k, Node* n)
		{
			Node* ptr = nodeExists(k);
			if(ptr==NULL)
			{
				cout << "No Node exists with the key value " << k << endl;
			}
			else
			{
				if(nodeExists(n->key)!=NULL)
				{
					cout << "Node already exists with key value : " << n->key << ". Append another node with different key value. " << endl;
				}
				else
				{
					n->next = ptr->next;
					ptr->next = n;
					cout << "Node Inserted. " << endl;
				}
			}
		}
		
		
		// Method : Delete Node By Unique Key
		void deleteNodeByKey(int k)
		{
			if(head=NULL)
			{
				cout << "Singly Linked List Already Emoty. Can't delete. " << endl;
			}
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head = head->next;
					cout << "Node Unlinked with keys value : " << k << endl;
				}
				else
				{
					Node* temp = NULL;
					Node* prevptr = head;
					Node* currentptr = head->next;
					
					while(currentptr!=NULL)
					{
						if(currentptr->key=k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						else
						{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					if(temp!=NULL)
					{
						prevptr->next = temp->next;
						cout << "Node UNLINKED with keys value : " << k << endl;
					}
					else
					{
						cout << "Node Doesn't exist with key value : " << k << endl;
					}
				}
			}
		}
		
		
		// Method : Update Node By Key
		void updateNodeByKey(int k, int d)
		{
			Node* ptr = nodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data = d;
				cout << "Node data updated successfully. " << endl;
			} 
			else
			{
				cout << "Node doesn't exist with key value : " << k << endl;
			}
		}
		
		// Method : Print The Whole List
		void printList()
		{
			if(head==NULL)
			{
				cout << "No nodes in singly linked list.";
			}
			else {
				cout << endl << "Singly Linked list values : ";
				Node* temp = head;
				
				while(temp!=NULL)
				{
					cout << "("<<temp->key<<","<<temp->data<<") -->";
					temp = temp->next;
				}
			}
		}
};

// Main Program Starts Here 
int main()
{
	SinglyLinkedList s;
	int option;
	int key1,k1,data1;
	do 
	{
		cout << "\nWhat operation do you want to perform? Select OPtion Number. Enter 0 to exit." << endl;
		cout << "1. appendNode() "	<< endl;
		cout << "2. prependNode() " << endl;
		cout << "3. insertNodeAfter() " << endl;
		cout << "4. deleteNodeByKey() " << endl;
		cout << "5. updateNodeByKey() " << endl;
		cout << "6. print() " << endl;
		cout << "7. Clear Screen" << endl << endl;
		
		cin >> option;
		Node* n1 = new Node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
				cin >> key1;
				cin >> data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
				
			case 2:
				cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended " << endl;
				cin >> key1;
				cin >> data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			
			case 3:
				cout << "Insert Node After OPeration \nEnter key of existing Node after which you want to Insert this new Node : " <<	endl;
				cin >> k1;
				cout << "Ente rkey & data of the New Node first : " << endl;
				cin >> key1;
				cin >> data1;
				n1->key=key1;
				n1->data=data1;
				
				s.insertNodeAfter(k1,n1);
				break;
				
				
			case 4:
				cout << "Delete Node by Key Operation - \nEnter key of the Node to be deleted: " << endl;
				cin >> k1;
				s.deleteNodeByKey(k1);
			
				break;
				
			case 5: 
				cout << "Update Node by Key Operation - \nEnter key & new Date to be updated " << endl;
				cin >> key1;
				cin >> data1;
				s.updateNodeByKey(key1, data1);
			 	break;
				 
			case 6:
				s.printList();
				break;
			
			case 7:
				system("cls");
				break;
				
			default:
				cout << "Enter proper Number " << endl;
		}
	} while(option!=0);
	
	return 0;
}
