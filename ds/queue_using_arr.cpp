#include<iostream>
#include<string>

using namespace std;

class Queue{
	private:
		int front;
		int rear;
		int arr[5];
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			for(int i = 0 ; i<5 ; i++)
				arr[i] = 0 ;
		}
		
		bool isEmpty()
		{
			if(front==-1 && rear==-1)
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
		
		void enqueue(int val)
		{
			if(isFull())
			{
				cout<<"The queue is full"<<endl;
			}
			else if(isEmpty())
			{
				rear=0;
				front=0;
				arr[rear]=val;
			}
			else
			{
				rear++;
				arr[rear]=val;
			}
		}
		
		int dequeue()
		{	
			int x;
			if(isEmpty())
			{
				cout<<"The queue is empty"<<endl;
				return 0;
			}
			else if(front==rear)
			{
				x=arr[front];
				arr[front]=0;
				// rear=front=-1 dentoes the queue is empty
				rear=-1;
				front=-1;
			}
			else
			{
				x=arr[front];
				arr[front]=0;
				front++;
			}
			
			return x;
		}
		
		int count()
		{	
			if(isEmpty())
				return 0;
			else
				return rear-front+1;
		}
		int display()
		{
			cout<<"-------------------------------"<<endl;
			for(int i=0;i<5;i++)
				cout<<arr[i]<<" ";
			cout<<"\n-------------------------------"<<endl;
		}
};

int main(){
	
	Queue q1;
	int option;
	int value;
	
	do
	{
		
		cout<<"Enter 0 to exit"<<endl;
		cout<<"1 Enqueue"<<endl;
		cout<<"2 Dequeue"<<endl;
		cout<<"3 isEmpty"<<endl;
		cout<<"4 isFull"<<endl;
		cout<<"5 count"<<endl;
		cout<<"6 display"<<endl;
		cout<<"7 Clear Screen"<<endl;
		
		cin>>option;
		
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enqueu called, enter an item"<<endl;
				cin>>value;
				q1.enqueue(value);
				break;
			case 2:
				cout<<"Deque called, dequeued value is "<<q1.dequeue()<<endl;
				break;
			case 3:
				if(q1.isEmpty())
					cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty"<<endl;
				break;
			case 4:
				if(q1.isFull())
					cout<<"Queue is full"<<endl;
				else
					cout<<"Queue is not full"<<endl;
				break;
			case 5:
				cout<<"Count of items is "<<q1.count()<<endl;
				break;
			case 6:
				cout<<"Display func called"<<endl;
				q1.display();
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter a valid command"<<endl;
		}
	} while(option!=0);
	return 0;
}
