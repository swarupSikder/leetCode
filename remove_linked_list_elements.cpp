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

    int x;
    cin>> x;

    Node* tmp = head;
    while(tmp != NULL){
        //delete head
        if(head->val == x){
            Node* deleteNode = head;
            head = head->next;
            tmp = head;
            delete deleteNode;
            continue;
        }

        if(tmp->next ==NULL){
            break;
        }

        //delete other nodes
        if(tmp->next->val == x){
            Node* deleteNode = tmp->next;
            tmp->next = tmp->next->next;
            delete deleteNode;
        }
        else{
            tmp = tmp->next;
        }
    }

    //print
    outputLinkedList(head);
    
    
    return 0;
}