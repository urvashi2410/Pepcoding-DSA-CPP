#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;

void removeFirst(){
    if(size == 0){
        cout << "List is empty" << endl;
    }
    else if (size == 1){
        head = tail = NULL;
        size = 0;
    }
    else{
        head = head->next;
        size--;
    }
}


int main(){
    return 0;
}