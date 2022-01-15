#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;
int size;

void reverse(){
    if(size <= 1){
        return;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* next = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    Node* temp = head;
    head = tail;
    tail = temp;
}

int main(){
    return 0;
}