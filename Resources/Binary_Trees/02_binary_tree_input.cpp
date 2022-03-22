#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int x){
    struct node* temp = new node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void print_tree(struct node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    if(root->left != NULL){
        cout << "L " << root->left->data;
    }
    if(root->right != NULL){
        cout << "R " << root->right->data;
    }
    cout << endl;
    print_tree(root->left);
    print_tree(root->right);
}

struct node* takeInput(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    struct node* root = createNode(data);
    struct node* leftData = takeInput();
    struct node* rightData = takeInput();
    root->left = leftData;
    root->right = rightData;
    return root;
}

int main(){
    struct node* root = takeInput();
    print_tree(root);
    return 0;
}