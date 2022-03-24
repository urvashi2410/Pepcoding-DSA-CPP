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

struct node* levelOrderInput(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    queue<struct node*>q;
    struct node* root = createNode(data);
    q.push(root);

    while(!q.empty()){
        struct node* Front = q.front();
        q.pop();

        cout << "Enter left child: " << Front->data << " : ";
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            struct node* leftChild = createNode(leftData);
            Front->left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter right child: " << Front->data << " : ";
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            struct node* rightChild = createNode(rightData);
            Front->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}

void levelorderPrinting(struct node* root){
    if(root == NULL){
        return;
    }

    queue<struct node*>q;
    q.push(root);
    while(!q.empty()){
        struct node* Front = q.front();
        cout << Front->data << " ";
        q.pop();

        if(Front->left != NULL){
            q.push(Front->left);
        }

        if(Front->right != NULL){
            q.push(Front->right);
        }
    }
}

int main(){
    struct node* root = levelOrderInput();
    levelorderPrinting(root);
    return 0;
}