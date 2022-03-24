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

struct node* levelorderInput(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    struct node* root = createNode(data);
    queue<struct node*>q;
    q.push(root);

    while(!q.empty()){
        struct node* Front = q.front();
        q.pop();

        cout << "Enter left child: "<< Front->data << " : ";
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

vector<int>rightView(struct node* root, vector<int>&res, int level){
    if(root == NULL){
        return res;
    }

    if(res.size() == level){
        res.push_back(root->data);
    }

    rightView(root->left, res, level+1);
    rightView(root->right, res, level+1);
    return res;
}

vector<int>rightViewIterative(struct node* root, vector<int>&res){
    if(root == NULL){
        return res;
    }

    queue<struct node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        int i = 0;

        while(i++ < n){
            struct node* Front = q.front();
            q.pop();

            if(i == n){
                res.push_back(Front->data);
            }

            if(Front->left != NULL){
                q.push(Front->left);
            }

            if(Front->right != NULL){
                q.push(Front->right);
            }
        }
    }
    return res;
}

int main(){
    struct node* root = levelorderInput();
    vector<int>res;
    rightViewIterative(root, res);
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}