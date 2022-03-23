#include<bits/stdc++.h>
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

void preOrder(struct node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

vector<int> preOrder_iteration(struct node* root){
    vector<int>pre;
    if(root == NULL){
        return pre;
    }

    stack<struct node*> s;
    s.push(root);

    while(!s.empty()){
        struct node* Top = s.top();
        s.pop();
        pre.push_back(Top->data);

        if(Top->right != NULL){
            s.push(Top->right);
        }
        if(Top->left != NULL){
            s.push(Top->left);
        }
    }
    return pre;
}

int main(){
    
}