#include<iostream>

using namespace std;

class Node{
	public:
		int key;
		int data;
		Node* next;
	Node()
	{
		key=0;
		data=0;
		next=NULL;
	}
	
	Node(int k, int d)
	{
		key=k;
		data=d;
	}
};

class CircularLinkedList{
	public:
		Node* head;
		
	CircularLinkedList()
	{
		head=NULL;
	};
	
	// 1. Check if Node Exists
	Node* nodeExists(int k)
	{	
		Node* temp = NULL;
		Node* ptr = head;
		
		if(ptr==NULL)
		{
			return temp;
		}
		else
		{
			do
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				
				ptr=ptr->next;
				
			}while(ptr!=head);
		}
		return temp;
	};
	
	// 2. Append a node to the list
	void appendNode(Node* n)
	{	
		cout<<"nodeexists? "<<nodeExists(n->key)<<endl;;
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Enter a unique key, duplicate key: "<<n->key<<endl;
		}
		else
		{	
			Node* ptr=head;
			if(ptr==NULL)
			{
				head=n;
				n->next=head;
				cout<<"Node appended as head"<<endl;
			}
			else
			{
				while(ptr->next!=head)
				{
					ptr = ptr -> next;
				}
				ptr -> next = n;
				n -> next = head;
				cout<<"Node appended at the end"<<endl;
			}
			
		}
	};
	
	void prependNode(Node* n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout<<"Enter a unique key, duplicate key: "<<n->key<<endl;
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<<"Node prepended as head"<<endl;
			}
			else
			{
				Node* ptr=head;
				while(ptr->next!=head)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				n->next=head;
				head=n;
				cout<<"Node prepended"<<endl;
			}
		}
	};
	
	void insertNodeAfter(int k, Node* n)
	{	
		Node* ptr= nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No node with key: "<<k<<endl;
		}
		else
		{
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Enter a unique key"<<endl;
			}
			else
			{
				if(ptr->next == head)
				{
					ptr->next=n;
					n->next=head;
					cout<<"Inserted node at the end"<<endl;
				}
				else
				{
					n->next=ptr->next;
					ptr->next=n;
					cout<<"Node insered in between"<<endl;
				}
			}
		}
	};
	
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"key: "<<k<<" not found, enter a valid key"<<endl;
		}
		else
		{
			if(ptr == head)
			{	
				if(head->next == head) //since its a circular list
				{	
					head=NULL;
					cout<<"Nothing to delete, list empty, head unlinked"<<endl;
				}
				else
				{
					Node* temp=head;
					while(temp->next!=head)
					{
						temp=temp->next;
					}
					temp->next=head->next;
					head=head->next;
					cout<<"Head Node Deleted/Unlinked"<<endl;	
				}	
			}
			else
			{
				Node* temp=NULL;
				Node* prevptr=head;
				Node* currentptr=head->next;
				
				while(currentptr != NULL)
				{
					if(currentptr->key==k)
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
				
				prevptr->next=temp->next;
				cout<<"Code unlinked with key: "<<k<<endl;
				
			}
		}
	};
	
	void updateNodeByKey(int k,int d)
	{	
		Node* ptr = nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"No node with key: "<<k<<" found"<<endl;
		}
		else
		{
			ptr->data=d;
			cout<<"Data Updated for the key: "<<k<<endl;
		}
	};
	
	// 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;
 
      Node * temp = head;
 
      do {
        cout << "(" << temp -> key << "," << temp -> data << "," << temp -> next << ") --> ";
        temp = temp -> next;
      } while (temp != head);
    }
 
  }
	
};

int main()
{	
	CircularLinkedList c;
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
				c.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend node, enter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				c.prependNode(n1);
				break;
			case 3:
				cout<<"insert node after, enter key of existing node after which you want to insert the node"<<endl;
				cin>>k1;
				cout<<"Enter key & data of the new node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				
				c.insertNodeAfter(k1, n1);
				break;
			case 4:
				cout<<"Delete node by key, enter key which node is to be deleted"<<endl;
				cin>>key1;
				c.deleteNodeByKey(key1);
				break;
			case 5:
				cout<<"Update Node by key, enter key of the node and the new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				c.updateNodeByKey(key1, data1);
				break;
			case 6:
				c.printList();
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
