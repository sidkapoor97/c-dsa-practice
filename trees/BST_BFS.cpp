#include<iostream>
#define SPACE 10

// Height of a tree -> The height of a Binary Tree is the number of edges b/w
// the tree's root and it's furthest leaf

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

    int CalculateHeight(TreeNode* r){
        if(r==NULL)
            return -1;
        int lheight=CalculateHeight(r->left);
        int rheight=CalculateHeight(r->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }

    // BFS TRAVERSAL
    void printLevelOrderBFS(TreeNode* r){
        int treeHeight = CalculateHeight(r);
        for(int i=0;i<=treeHeight;i++)
            printGivenLevel(r,i);
    }

    void printGivenLevel(TreeNode* r, int level){
        if(r==NULL)
            return;
        else if(level == 0)
            std::cout<<r->value<<" ";
        else{
            printGivenLevel(r->left,level-1);
            printGivenLevel(r->right,level-1);
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
};

int main()
{   
    int value;
    int option;
    int treeHeight;
    BST obj;
    do
    {
        std::cout<<"Enter 0 to exit\n";
        std::cout<<"Enter 1 to insertNode\n";
        std::cout<<"Enter 2 to Search Node\n";
        std::cout<<"Enter 3 to Delete Node\n";
        std::cout<<"Enter 4 to Print BST Values\n";
        std::cout<<"Enter 5 to Calculate Height of the Binary Tree\n";
        std::cout<<"Enter 6 to Clear screen\n";
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
            std::cout<<"\n";
            std::cout<<"BFS TRAVERSAL\n";
            obj.printLevelOrderBFS(obj.root);
            std::cout<<"\n";
            break;
        case 5:
            std::cout<<"CALCULATE HEIGHT\n";
            treeHeight = obj.CalculateHeight(obj.root);
            if(treeHeight == -1)
                std::cout<<"EMPTY TREE\n";
            else
                std::cout<<"The height of the Binary Tree is "<<treeHeight<<"\n";
            break;
        case 6:
            system("cls");
            break;
        default:
            std::cout<<"ENTER A VALID COMMAND\n";
            break;
        }
    } while (option!=0);
    
    return 0;
}