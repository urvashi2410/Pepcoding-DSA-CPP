#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int height(struct node* root){
    if(root == NULL){
        return 0;
    }

    int leftSubtreeHeight = height(root->left);
    int rightSubtreeHeight = height(root->right);
    return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
}

int main(){

}