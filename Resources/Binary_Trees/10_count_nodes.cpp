#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int countNodes(struct node* root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){

}