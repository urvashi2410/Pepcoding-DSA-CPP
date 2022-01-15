#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;
int size;

int getFirst(){
    if(size == 0){
        cout << "List is empty" << endl;
        return -1;
    }
    else{
        return head->data;
    }
}

// last node is stored in tail because of addLast function 
int getLast(){
    if(size == 0){
        cout << "List is empty" << endl;
        return -1;
    }
    else{
        return tail->data;
    }
}

int getIndexAt(int index){
    if(size == 0){
        cout << "List is empty" << endl;
        return -1;
    }
    else if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return -1;
    }
    else{
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
}

int main(){
    return 0;
}