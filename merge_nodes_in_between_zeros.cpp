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

    //merge
    int sum = 0;
    Node* tmp = head;
    tmp = tmp->next;            //tmp will start after the first zero
    Node* newHead = NULL;       //newHead will start from here
    Node* newTail = NULL;

    while(tmp != NULL){
        if(tmp->val == 0){
            inputLinkedList(newHead, newTail, sum);
            sum = 0;
        }

        sum += tmp->val;
        tmp = tmp->next;
    }


    //print
    outputLinkedList(newHead);
    
    
    return 0;
}