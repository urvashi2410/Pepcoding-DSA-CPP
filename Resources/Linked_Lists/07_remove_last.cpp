#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;

void removeLast(){
    if(size == 0){
        cout << "List is empty" << endl;
    }
    else if (size == 1){
        head = tail = NULL;
        size = 0;
    }
    else{
        
        // temp me last wali node se ek pehle wale ko store kr liya taaki uska next change krde to null
        Node* temp = head;
        for(int i = 0; i < size - 2; i++){
            temp = temp->next;
        }
        
        tail = temp;
        tail->next = null;
        size--;
    }
}


int main(){
    return 0;
}