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

vector<int> reverseLevelOrder(struct node* root){
    queue<struct node*>q;
    q.push(root);

    vector<int>ans;
    while(!q.empty()){
        struct node* Front = q.front();
        ans.push_back(Front->data);
        q.pop();

        if(Front->right != NULL){
            q.push(Front->right);
        }

        if(Front->left != NULL){
            q.push(Front->left);
        }
    }
    return ans;
}

int main(){
    struct node* root = takeInput();
    reverseLevelOrder(root);
    return 0;
}