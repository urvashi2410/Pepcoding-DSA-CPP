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

void printLevelOrder(struct node* root){
    queue<struct node*>q;
    q.push(root);

    while(!q.empty()){
        struct node* Front = q.front();
        cout << q.front() << " ";
        q.pop();

        if(Front->left != NULL){
            q.push(Front->left);
        }
        if(Front->right != NULL){
            q.push(Front->right);
        }
    }
}

struct node* takeInput(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    struct node* root = createNode(data);
    struct node* leftChild = takeInput();
    struct node* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;
    return root;
}

vector<int>Print_levelorder(struct node* root){
    queue<struct node*>q;
    q.push(root);
    vector<int>ans;

    while(!q.empty()){
        struct node* Front = q.front();
        ans.push_back(Front->data);
        q.pop();

        if(Front->left != NULL){
            q.push(Front->left);
        }

        if(Front->right != NULL){
            q.push(Front->right);
        }
    }
    return ans;
}

int main(){
    struct node* root = takeInput();
    Print_levelorder(root);
    return 0;
}