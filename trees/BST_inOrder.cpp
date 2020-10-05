#include<iostream>
#define SPACE 10

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

class BST{
public:
    TreeNode* root;
    BST(){
        root=NULL;
    }
    bool isEmpty(){
        if(root==NULL)
            return true;
        else
            return false;
    }
    void InsertNode(TreeNode* newNode){
        if(root==NULL){
            root=newNode;
            std::cout<<"INSERTED AT ROOT NODE\n";
        }
        else
        {
            TreeNode* temp=root;
            while (temp!=NULL)
            {
                if(newNode->value == temp->value){
                    std::cout<<"DUPLICATES NOT ALLOWED\n";
                    return;
                } else if((newNode->value < temp->value) && (temp->left == NULL)){
                    temp->left = newNode;
                    std::cout<<"NODE INSERTED ON THE LEFT\n";
                    return;
                } else if(newNode->value < temp->value){
                    temp = temp->left;
                } else if(newNode->value > temp->value &&(temp->right == NULL)){
                    temp->right = newNode;
                    std::cout<<"NODE INSERTED ON THE RIGHT\n";
                    return;
                } else{
                    temp=temp->right;
                }
            }
            
        }
    }
    void print2D(TreeNode* r,int space){
        if(r==NULL)
            return;
        space+=SPACE;
        print2D(r->right,space);
        std::cout<<"\n";
        for(int i=SPACE;i<space;i++)
            std::cout<<" ";
        std::cout<<r->value<<"\n";
        print2D(r->left,space);
    }

    void printInOrder(TreeNode* r){
        if(r==NULL)
            return;
        printInOrder(r->left);
        std::cout<<r->value<<" | ";
        printInOrder(r->right);
    }
};

int main()
{   
    int value;
    int option;
    BST obj;
    do
    {
        std::cout<<"Enter 0 to exit\n";
        std::cout<<"Enter 1 to insertNode\n";
        std::cout<<"Enter 2 to Search Node\n";
        std::cout<<"Enter 3 to Delete Node\n";
        std::cout<<"Enter 4 to Print BST Values\n";
        std::cout<<"Enter 5 to Clear screen\n";
        std::cin>>option;
        TreeNode* newNode = new TreeNode();
        switch (option)
        {
        case 0:
            std::cout<<"EXIT!!\n";
            break;
        case 1:
            std::cout<<"INSERT NODE\n";
            std::cout<<"Enter the value\n";
            std::cin>>value;
            newNode->value = value;
            obj.InsertNode(newNode);
            break;
        case 2:
            std::cout<<"SEARCH NODE!!\n";
            break;
        case 3:
            std::cout<<"DELETE NODE\n";
            break;
        case 4:
            std::cout<<"PRINT 2D\n";
            obj.print2D(obj.root,5);
            std::cout<<"\nIN-ORDER TRAVERSAL\n";
            obj.printInOrder(obj.root);
            std::cout<<"\n";
            break;
        case 5:
            system("cls");
            break;
        default:
            std::cout<<"ENTER A VALID COMMAND\n";
            break;
        }
    } while (option!=0);
    
    return 0;
}