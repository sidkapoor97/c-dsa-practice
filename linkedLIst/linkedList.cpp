#include<iostream>
using namespace std;

class Node{
	public:
		 int key;
		 int data;
		 Node* next;
	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k,int d)
	{
		key=k;
		data=d;
	}
};

class SinglyLinkedList{
	public:
		Node *head;
		
	SinglyLinkedList()
	{
		head=NULL;
	}
	SinglyLinkedList(Node *n)
	{
		head=n;
	}
	
	// 1. Check if a node exists or not,  return the ptr to that node else return NULL
	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		
		Node* ptr = head;
		
		while(ptr != NULL)
		{
			if(ptr->key == k)
			{
				temp=ptr;
			}
			ptr=ptr->next;
		}
		return temp;
	}
	
	// 2. Append a node (to the end)
	void appendNode(Node *n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Provide an unique key, duplicate key: "<<n->key<<endl;
		}
		else
		{	
			if(head == NULL)
			{
				head = n;
				cout<<"Node Appended"<<endl;
			}
			else
			{
				Node* ptr=head;
				while(ptr->next != NULL)
				{
					ptr=ptr->next;
				}
				
				ptr->next=n;
				cout<<"Node Appened"<<endl;
				//n->next=NULL;
			}
		}
	}
	
	// 3. Prepend Node - Attach a node at the start
	void prependNode(Node* n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Provide an unique key, duplicate key: "<<n->key<<endl;
		}
		else
		{
			n->next=head;
			head = n;
			cout<<"Node Prepended"<<endl;
		}
	}
	
	// 4. Insert a Node after a particular node in the list
	// k - after which node to insert the new node 'n'
	// n - node to be inserted
	void insertNode(int k, Node* n)
	{	
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No such node exists with the key: "<<k<<endl;
		}
		else
		{	
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Node already exists with the same key, duplicate key error"<<endl;
			}
			else
			{
				n->next=ptr->next;
				ptr->next=n;
				cout<<"Node inserted after key: "<<k<<endl;
			}
		}
	}
	
	// 5. Delete a node after a key
	void deleteNodeByKey(int k)
	{
		if(head==NULL)
		{
			cout<<"List is empty, cant delete anything"<<endl;
		}
		else if(head!=NULL)
		{
			if(head->key==k)
			{
				head=head->next;
				cout<<"Node Unlinked with keys value: "<<k<<endl;
			}
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				
				while(currentptr != NULL)
				{
					if(currentptr->key == k)
					{
						temp=currentptr;
						currentptr=NULL;
					}
					else
					{
						prevptr=prevptr->next;
						currentptr=currentptr->next;
					}
				}
				
				if(temp!=NULL)
				{
					prevptr->next = temp->next;
					cout<<"Node Unlinked after key value: "<<k<<endl;
				}
				else
				{
					cout<<"Node doesnt exist the node with key value: "<<k<<endl;
				}
			}
		}
	}
	
	// 6. Update Node Data by Key
	void updateNodeByKey(int k,int d)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No such node with key: "<<k<<endl;
		}
		else
		{
			ptr->data=d;
			cout<<"Data is updated successfully"<<endl;
		}
	}
	
	// 7. Printing
	void printList()
	{
		if(head==NULL)
		{
			cout<<"Empty List"<<endl;
		}
		else
		{
			Node* ptr=head;
			while(ptr != NULL)
			{
				cout<<"----------"<<endl;
				cout<<"key: "<<ptr->key<<" Data: "<<ptr->data<<endl;
				ptr = ptr->next;
			}
			cout<<"----------"<<endl;
		}
	}
};
int main()
{	
	
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	
	do
	{
		cout<<"Enter 0 to exit"<<endl;
		cout<<"Enter 1 to appendNode"<<endl;
		cout<<"Enter 2 to prependNode"<<endl;
		cout<<"Enter 3 to insertNodeAfter"<<endl;
		cout<<"Enter 4 to deleteNode"<<endl;
		cout<<"Enter 5 to updateNodeByKey"<<endl;
		cout<<"Enter 6 to print"<<endl;
		cout<<"Enter 7 to Clear Screen"<<endl;
		
		cin>>option;
		
		Node* n1 = new Node();
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Append a node, enter key and data to be appended"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				// we can pass n1 since we are using n1 so that we can use DMA -> global
				s.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend node, enter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"insert node after, enter key of existing node after which you want to insert the node"<<endl;
				cin>>k1;
				cout<<"Enter key & data of the new node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				
				s.insertNode(k1, n1);
				break;
			case 4:
				cout<<"Delete node by key, enter key which node is to be deleted"<<endl;
				cin>>key1;
				s.deleteNodeByKey(key1);
				break;
			case 5:
				cout<<"Update Node by key, enter key of the node and the new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1, data1);
				break;
			case 6:
				s.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter a proper command"<<endl;
		}
	} while(option!=0);
	return 0;
	
}
