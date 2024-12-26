//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

void inputLinkedList(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    //Edge case, (if linked list is empty)
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int listSize(Node* head){
    int i=0;
    Node* tmp = head;
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

void outputLinkedList(Node* head){
    if(head == NULL){
        cout<< "" <<endl;
        return;
    }

    Node* tmp = head;
    while(tmp != NULL){
        //print the node
        cout<< tmp->val;

        //control trailing spaces
        (tmp->next == NULL)? std::cout<<endl : std::cout<<" ";

        //forward the node
        tmp = tmp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(1){
        cin>> val;
        if(val == -1) break;
        inputLinkedList(head, tail, val);
    }

    //swap position
    int idx;
    cin>> idx;

    //swap task
    int size = listSize(head);

    //first loop
    Node* tmp1 = head;
    for(int i=1; i<idx ;i++){
        tmp1 = tmp1->next;
    }

    //second loop
    Node* tmp2 = head;
    for(int i=1; i<=size-idx ;i++){
        tmp2 = tmp2->next;
    }

    //swap now
    swap(tmp1->val, tmp2->val);

    //print
    outputLinkedList(head);
    
    return 0;
}