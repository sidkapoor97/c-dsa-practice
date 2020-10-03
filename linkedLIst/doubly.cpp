#include<iostream>
using namespace std;

class Node
{
	public:
		int key;
		int data;
		Node* next;
		Node* previous;
	
	Node()
	{
		key=0;
		data=0;
		next=NULL;
		previous=NULL;
	}
	
	Node(int k,int d)
	{
		key=k;
		data=d;
	}
};

class DoublyLinkedList
{
	public:
		Node* head;
	
	DoublyLinkedList()
	{
		head=NULL;
	}
	
	DoublyLinkedList(Node* n)
	{
		head=n;
	}
	
	// 1. Check if a node exists using key value
	Node* nodeExists(int k)
	{
		Node* temp=NULL;
		Node* ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->key==k)
				{
					temp=ptr;
				}
			ptr=ptr->next;
		}
		
		return temp;
	};
	
	// 2. Append a node to the list
	void appendNode(Node* n)
	{
		if(nodeExists(n->key)!=NULL)
		{
			cout<<"Use an unique key: duplicate key -> "<<n->key<<endl;
		}
		else
		{	
			
			if(head==NULL)
			{
				head=n;
				cout<<"Node Appended after head"<<endl;
			}
			else
			{
				Node* ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				
				ptr->next=n;
				n->previous=ptr;
				cout<<"Node appended at the end"<<endl;	
			}
		}
	};
	
	// 3. prepend a node
	void prependNode(Node* n)
	{	
		if(nodeExists(n->key)!=NULL)
		{
			cout<<"Use an unique key: duplicate key -> "<<n->key<<endl;
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
					head->previous=n;
					n->next=head;
					head=n;
					cout<<"Node Prepended"<<endl;
				}
		}
	};
	
	// 4. Insert Node After using a key
	void insertNodeAfter(int k, Node* n)
	{	
		Node* ptr=nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"Key: "<<k<<" not present in the doubly linked list"<<endl;
		}
		else
		{
			if(nodeExists(n->key) != NULL)
			{
				cout<<"Enter a valid key for the new node"<<endl;
			}
			else
			{
				Node* nextNode = ptr->next;
				
				//inserting at the end
				if(nextNode == NULL)
				{
					ptr->next = n;
					n->previous = ptr;
					cout<<"Node inserted at the end"<<endl;
				}
				//inserting in between
				else
				{
					ptr->next=n;
					n->next=nextNode;
					n->previous=ptr;
					nextNode->previous=n;
					
					cout<<"Node inserted in between"<<endl;
				}
			}
		}
	};
	
	// 5. delete node by key
	void deleteNodeByKey(int k)
	{
		Node* ptr=nodeExists(k);
		if(ptr==NULL)
		{
			cout<<"Key: "<<k<<" not present in the doubly linked list"<<endl;
		}
		else
		{
			if(head==NULL)
			{
				cout<<"List is empty, cant delinked"<<endl;
			}
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"1st node delinked"<<endl;
				}
				else
				{
					Node* prevNode=ptr->previous;
					Node* nextNode=ptr->next;
					
					if(nextNode==NULL)
					{
						prevNode->next=NULL;
						cout<<"Last Node delinked"<<endl;	
					}		
					else
					{
						prevNode->next=nextNode;
						nextNode->previous=prevNode;
						cout<<"Node delinked in between"<<endl;	
					}
				}
			}
		}
	};
	
	// 6. update the node
	void updateNodeByKey(int k, int d)
	{
		Node* ptr=nodeExists(k);
		if(ptr == NULL)
		{
			cout<<"Key: "<<k<<" not present in the doubly linked list"<<endl;
		}
		else
		{
			ptr->data=d;
			cout<<"Data Updated"<<endl;
		}
	};
	
	// 7. print the list 
	void printList()
	{
		if(head==NULL)
		{
			cout<<"List is empty"<<endl;
		}
		else
		{	
			Node* ptr;
			ptr=head;
			while(ptr!=NULL)
			{
				cout<<"("<<ptr->key<<","<<ptr->data<<")"<<endl;
				ptr=ptr->next;
			}
				
		}
	};
};



int main()
{	
	
	DoublyLinkedList obj;
	int option;
	int key1,k1,data1;
	
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
				obj.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend node, enter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				obj.prependNode(n1);
				break;
			case 3:
				cout<<"insert node after, enter key of existing node after which you want to insert the node"<<endl;
				cin>>k1;
				cout<<"Enter key & data of the new node"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				
				obj.insertNodeAfter(k1, n1);
				break;
			case 4:
				cout<<"Delete node by key, enter key which node is to be deleted"<<endl;
				cin>>key1;
				obj.deleteNodeByKey(key1);
				break;
			case 5:
				cout<<"Update Node by key, enter key of the node and the new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				obj.updateNodeByKey(key1, data1);
				break;
			case 6:
				obj.printList();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter a proper command"<<endl;
		}
	}while(option!=0);
	
	return 0;
}
