#include<iostream>

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
    Node(int k,int d)
    {
        key=k;
        data=d;
    }
};

class Stack{
public:
    Node* top;
    Stack(){
        top=NULL;
    }
    bool isEmpty(){
        if(top==NULL)
        {   
            return true;
        }
        else
        {
            return false;
        }
    }
    bool CheckIfNodeExists(int k){
        Node* temp=top;
        while(temp!=NULL){
            if(temp->key==k)
                return true;
            else{
                temp=temp->next;
            }
        }
        return false;
    }
    void pushNode(Node *n){
        if(top==NULL)
            top=n;
        else if(CheckIfNodeExists(n->key))
            std::cout<<"Enter node with unique key\n";
        else
        {
            Node* temp=top;
            top=n;
            n->next=temp;
            std::cout<<"NODE PUSHED\n";
        }
    }
    void count(){
        Node* ptr=top;
        int count=0;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        std::cout<<"Number of Nodes: "<<count<<"\n";
    }
    void pop(){
        top=top->next;
        std::cout<<"NODE POPPED\n";
    }
    void peek(){
        if(isEmpty())
            std::cout<<"Stack UNDERFLOW\n";
        else
            printf("[%d,%d]\n",top->key,top->data);
    }
    void display(){
        if(isEmpty())
        {   
            std::cout<<"Stack UNDERFLOW\n";
        }
        else
        {
            Node* ptr=top;
            while(ptr!=NULL)
            {
                printf("[%d,%d]\t",ptr->key,ptr->data);
                ptr=ptr->next;
            }
            printf("\n");
        }
    }
};

int main()
{   
    int option;
    int key,value;
    Stack s;

    do
    {   
        std::cout<<"0 to exit\n";
        std::cout<<"1 to push\n";
        std::cout<<"2 to pop\n";
        std::cout<<"3 to count\n";
        std::cout<<"4 to peek\n";
        std::cout<<"5 to display\n";
        std::cout<<"6 to clear screen\n";
        std::cin>>option;
        Node* n1 = new Node();
        
        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout<<"Enter key and value\n";
            std::cin>>key>>value;
            n1->data=value;
            n1->key=key;
            s.pushNode(n1);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.count();
            break;
        case 4:
            s.peek();
            break;
        case 5:
            s.display();
            break;
        case 6:
            system("cls");
        default:
            std::cout<<"Enter a valid option\n";
                break;
        }
    } while (option!=0);
    
    return 0;
}