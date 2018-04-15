#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;
vector<int> dataOfNodes;

node* newNode(); //creates and returns a new node
void makeBST(node **n, int f_ind, int l_ind);//creates a BST
node* treeSearch(node* start, int key);//search an element in BST
void insertNode(node* t, node* z);//inserts a node in BST
void displayMessage();//display message to interact with user
node* successorOf(int n);//finds successor of n. but it is not yet implemented

int main()
{
    int input;
    node* root;
    node* temp;
    int action;
    puts("Enter value of nodes. Enter negative value to exit:-");
    while(true)
    {
        cin >> input;
        if(input<0) break;
        dataOfNodes.push_back(input);
    }
    root=newNode();
    makeBST(&root, 0, dataOfNodes.size()-1);
    while(true)
    {
        displayMessage();
        cin >> action;
        if(action==4) return 0;
        else if(action==3)
        {
            cout <<"Enter data you want successor of: ";
            cin >> input;
            temp=successorOf(input);
            if(temp==NULL) printf("Successor not found");
            else printf("Successor of %d is %d\n", input, temp->data);
        }
        else if(action==2)
        {
            cout << "Enter data you want to search: ";
            cin >> input;
            temp=treeSearch(root, input);
            if(temp==NULL) puts("NotFound");
            else puts("FOUND");
        }
        else if(action==1)
        {
            cout << "Enter data you want to insert: ";
            cin >> input;
            temp=newNode();
            temp->data=input;
            insertNode(root, temp);
        }
    }
    //recursive(root);
}

node* newNode()
{
    node* n = (node*) malloc(sizeof(node));
    n->data=-10;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void makeBST(node **n, int f_ind, int l_ind)
{
    if(f_ind>l_ind)
    {
        (*n)=NULL;
        return;
    }
    int mid=(f_ind+l_ind)/2;
    (*n)->left=newNode();
    (*n)->right=newNode();
    (*n)->data=dataOfNodes[mid];
    makeBST(&(*n)->left, f_ind, mid-1);
    makeBST(&(*n)->right, mid+1, l_ind);
}

node* treeSearch(node* start, int key)
{
    if(start==NULL || key==start->data)
    {
        return start;
    }
    if(key<=start->data)
    {
        return treeSearch(start->left, key);
    }
    else
    {
        return treeSearch(start->right, key);
    }
}

void insertNode(node* t, node* z)
{
    node* y = NULL;
    node* x = t;
    while(x!=NULL)
    {
        y=x;
        if(z->data<x->data)
        {
            x=x->left;
        }
        else
        {
            x=x->right;
        }
    }
    //z.p=y
    if(y==NULL)
    {
        t=z;
    }
    else if(y->data==z->data)
        y->left=z;
    else y->right=z;
}

void displayMessage()
{
    cout << "Enter 1 to insert" << endl;
    cout << "Enter 2 to search" << endl;
    cout << "Enter 3 to search successor" << endl;
    cout << "Enter 4 to quit" << endl;
    cout << "Please enter:";
}

node* successorOf(int n)
{
    puts("this function is not completed yet");
    return NULL;
}
