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
}

struct node* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int inS, int inE, int preS, int preE){
    if(inS > inE){
        return NULL;
    }

    int rootData = preorder[preS];
    int rootIdx;
    for(int i = inS; i <= inE; i++){
        if(rootData == inorder[i]){
            rootIdx = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIdx - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIdx + 1;
    int rinE = inE;
    int rpreS = preS + 1;
    int rpreE = preE;
    struct node* root = createNode(rootData);
    root->left = buildTreeHelper(preorder, inorder, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(preorder, inorder, rinS, rinS, rpreS, rpreE);
    return root;

}
struct node* buildTree(vector<int> &preorder, vector<int> &inorder){
    int n = preorder.size();
    return buildTreeHelper(preorder, inorder, 0, n-1, 0, n-1);
}
int main(){
}