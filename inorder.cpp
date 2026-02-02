#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    /*
            4
           / \
          2   6
         / \ / \
        1  3 5  7
    */
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(7);

    cout<<"Inorder DFS Traversal: ";
    inorder(root);
    cout<<"\nPreorder DFS Traversal: ";
    preorder(root);
    cout<<"\nPostorder DFS Traversal: ";
    postorder(root);
    cout<<endl;

    return 0;
}