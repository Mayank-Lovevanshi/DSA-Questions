#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
int data;
Node* left;
Node* right;
Node(int val)
{
this->data = val;
left = NULL;
right = NULL;
}
};

void printBinaryTree(Node *root)
{
if(!root) return;
cout<<root->data<<" ";
printBinaryTree(root->left);
printBinaryTree(root->right);
}

int main()
{
int n;
cout<<"Enter root node : ";
cin>>n;
Node *root = new Node(n);
queue<Node*> q;
q.push(root);
while(!q.empty())
{
Node* temp = q.front();
q.pop();
int leftChild;
int rightChild;
cout<<"Enter left child of "<<temp->data<<" : ";
cin>>leftChild;
if(leftChild!=-1)
{
temp->left = new Node(leftChild);
q.push(temp->left);
}
cout<<"Enter right child of "<<temp->data<<" : ";
cin>>rightChild;
if(rightChild!=-1)
{
temp->right = new Node(rightChild);
q.push(temp->right);
}
}
printBinaryTree(root);
}
