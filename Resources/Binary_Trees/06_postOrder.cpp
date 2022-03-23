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

void postOrder(struct node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

vector<int> preOrder_traversal(struct node* root){
    vector<int>post;
    if(root == NULL){
        return post;
    }

    stack<struct node*>s;
    s.push(root);
    while(!s.empty()){
        struct node* Top = s.top();
        s.pop();
        post.push_back(Top->data);

        if(Top->left != NULL){
            s.push(Top->left);
        }

        if(Top->right != NULL){
            s.push(Top->right);
        }
    }
}

int main(){

}