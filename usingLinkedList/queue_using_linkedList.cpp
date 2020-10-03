#include<iostream>

class Node{
public:
    int key;
    int data;
    Node* next;
    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
        next=NULL;
    }
};

class Queue{
public:
    Node* front;
    Node* rear;
    Queue(){
        front=NULL;
        rear=NULL;
    }
    bool CheckIfNodeExists(int k){
        Node* ptr=front;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
                return true;
            ptr=ptr->next;
        }
        return false;
    }
    bool IsEmpty(){
        if(front==NULL && rear==NULL)
            return true;
        else
            return false;
    }
    void enqueue(Node *n){
        if(IsEmpty())
        {
            front=n;
            rear=n;
            std::cout<<"Node ENQUEUED\n";
        }
        else if(CheckIfNodeExists(n->key))
        {
            std::cout<<"Enter UNIQUE key\n";
        }
        else
        {
            rear->next=n;
            rear=n;
            std::cout<<"Node ENQUEUED\n";
        }
    }
    void dequeue(){
        Node* ptr=front;
        if(IsEmpty())
            std::cout<<"Nothing to remove\n";
        else
        {   
            if(front==rear)
            {
                front=NULL;
                rear=NULL;
                std::cout<<"Node REMOVED\n";
            }
            else{
                front=front->next;
                std::cout<<"Node REMOVED\n";
            }
        }
    }

    void count(){
        int count=0;
        if(IsEmpty())
            std::cout<<"Count: 0\n";
        else if(front==rear)
            std::cout<<"Count: 1\n";
        else
        {   
            Node* ptr=front;
            while(ptr!=rear)
            {
                count++;
                ptr=ptr->next;
            }
            std::cout<<"Count: "<<count+1<<"\n";
        }
    }

    void display(){
        if(IsEmpty())
            std::cout<<"Queue is EMPTY\n";
        else if(front==rear)
        {
            printf("[%d,%d]\n",front->key,front->data);

        }
        else
        {
            Node* ptr=front;
            while(ptr!=rear)
            {
                printf("[%d,%d]\t",ptr->key,ptr->data);
                ptr=ptr->next;
            }
            printf("[%d,%d]\n",rear->key,rear->data);
        }
    }
};

int main()
{   
    int option;
    int key,value;
    Queue q;
    do
    {
        std::cout<<"0 to exit\n";
        std::cout<<"1 to enqueue\n";
        std::cout<<"2 to dequeue\n";
        std::cout<<"3 to count\n";
        std::cout<<"4 to display\n";
        std::cout<<"5 to clear screen\n";
        std::cin>>option;
        Node* n1=new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            std::cout<<"Enter key and value\n";
            std::cin>>key>>value;
            n1->key=key;
            n1->data=value;
            q.enqueue(n1);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.count();
            break;
        case 4:
            q.display();
            break;
        case 5:
            system("cls");
            break;
        default:
            std::cout<<"Enter a valid command\n";
            break;
        }
    } while (option!=0);
    
    return 0;
}