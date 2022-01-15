#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
int size;

void display(){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int findSize(int val){
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
    
    return size;
}

int main(){
    return 0;
}