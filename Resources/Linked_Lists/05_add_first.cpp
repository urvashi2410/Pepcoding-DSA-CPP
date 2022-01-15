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

int main(){
    return 0;
}