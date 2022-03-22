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

void printLeft(struct node* root){
    while(root != NULL){
        cout << root->data << endl;
        root = root->left;
    }
}

void printRight(struct node* root){
    while(root != NULL){
        cout << root->data << endl;
        root = root->right;
    }
}

int main(){
    struct node* root = createNode(5);
    root->left = createNode(10);
    root->right = createNode(15);
    root->left->left = createNode(34);
    root->right->left = createNode(9);
    printLeft(root);
    return 0;
}