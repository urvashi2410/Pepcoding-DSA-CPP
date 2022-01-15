#include <bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* next;
}

Node* head;
Node* tail;
int size;

void addFirst(int val){
    
    // banao, val daalo, pehle wali first node pr point krdo ise jiska address head me h to usse lelo, head ko ispr point krdo
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
    
    // if pehle khali thi list to last bn jaegi na ye wali node isliye tail me store krdo
    if(size == 0){
        tail = temp;
    }
    
    size++;
}

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

void addAtIndex(int index, int val){
    if(index < 0 || index > size){
        cout << "Invalid arguments" << endl;
    }
    else if(index == 0){
        addFirst(val);
    }
    else if(index == size){
        addLast(val);
    }
    else{
        Node* node = new Node();
        node->data = val;
        
        Node* temp = head;
        
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        
        node->next = temp->next
        
        temp->next = node;
        size++;
    }
}
int main(){
    return 0;
}