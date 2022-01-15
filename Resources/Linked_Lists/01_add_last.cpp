#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;
int size;

void addLast(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    
    if(size == 0){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
    size++;
}

int main(){
    return 0;
}