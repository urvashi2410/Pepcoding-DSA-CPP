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

void removeAt(int index){
    if(index < 0 || index >= size){
        cout << "Invalid arguments" << endl;
    }
    else if(index == 0){
        removeFirst();
    }
    else if(index == size - 1){
        removeLast();
    }
    else{
        // temp me store kr liya index se ek pehle wali node ko or fir uske next ko next to next me point kra diya size decrease krke kaam khtm
        Node* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        size--;
    }
}
int main(){
    return 0;
}