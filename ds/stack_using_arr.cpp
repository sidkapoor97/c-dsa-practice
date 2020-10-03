#include<iostream>
#include<string>

using namespace std;
class Stack {
	private:
		int top;
		int arr[5];
		
	public:
		Stack()
		{
			top = -1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		
		bool isEmpty()
		{
			if(top == -1)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(top == 4)
				return true;
			else
				return false;
		}
		
		void push(int val)
		{
			if(isFull())
			{
				cout<<"Stack Overflow"<<endl;
			}
			else
			{
				top++;
				arr[top]=val;
			}
		}
		
		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
				return 0;
			}
			else
			{
				int popValue = arr[top];
				arr[top]=0;
				top--;
				return popValue;
			}
		}
		
		int count()
		{
			return (top+1);
		}
		
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
				return 0;
			}
			else
			{
				return arr[pos];
			}
		}
		
		void change(int pos, int val)
		{
			arr[pos]=val;
			cout<<"value changed at location "<<pos<<endl;
		}
		void display()
		{	
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
			}
			else
			{
				cout<<"All Values in the stack are "<<endl;
				for(int i = 4 ; i>-1 ; i--)
					cout<<arr[i]<<endl;	
			}
		}
};

int main()
{	
	
	Stack s1;
	int option, position, value;
	
	do
	{
		cout<<"0 for exit"<<endl;
		cout<<"1 for Push"<<endl;
		cout<<"2 for Pop"<<endl;
		cout<<"3 for isEmpty"<<endl;
		cout<<"4 for isFull"<<endl;
		cout<<"5 for peek"<<endl;
		cout<<"6 for count"<<endl;
		cout<<"7 for change"<<endl;
		cout<<"8 for display"<<endl;
		cout<<"9 for Clear Screen"<<endl;
		
		cin>>option;
		switch(option)
		{	
			case 0:
				break;
			case 1:
				cout<<"Enter an item to be pushed"<<endl;
				cin>>value;
				s1.push(value);
				break;
			case 2:
				cout<<"Pop called - popped value "<<s1.pop()<<endl;
				break;
			case 3:
				cout<<"Stack is empty? "<<s1.isEmpty()<<endl;
				break;
			case 4:
				cout<<"Stack is full? "<<s1.isFull()<<endl;
				break;
			case 5:
				cout<<"Enter position you want to peek"<<endl;
				cin>>position;
				cout<<"Peek called - Value at position "<<position<<" is "<<s1.peek(position)<<endl;
				break;
			case 6:
				cout<<"Count called No. of items are "<<s1.count()<<endl;
				break;
			case 7:
				cout<<"Chnage func called"<<endl;
				cout<<"Enter pos you want to change"<<endl;
				cin>>position;
				cout<<"Enter value to be changed to"<<endl;
				cin>>value;
				s1.change(position, value);
				break;
			case 8:
				cout<<"Display called"<<endl;
				cout<<"-----------------------------------------"<<endl;
				s1.display();
				cout<<"-----------------------------------------"<<endl;
				break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"Enter proper option number"<<endl;
				
		}
	}while(option!=0);
	
	return 0;
}
