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
    //list 1
    Node* head1 = NULL;
    Node* tail1 = NULL;

    int val;
    while(1){
        cin>> val;
        if(val == -1) break;
        inputLinkedList(head1, tail1, val);
    }

    //list 2
    Node* head2 = NULL;
    Node* tail2 = NULL;

    while(1){
        cin>> val;
        if(val == -1) break;
        inputLinkedList(head2, tail2, val);
    }

    //size
    int size = listSize(head1);

    //merge ranges [a,b]
    int a,b;
    cin>> a >> b;
    a++;                //convert to 1 based
    b++;                //convert to 1 based

    //merge
    Node* tmpA = head1;
    Node* tmpB = head1;

    for(int i=0; i<size ;i++){
        if(i<a-2){
            tmpA = tmpA->next;
        }

        if(i==a-2){
            tmpB = tmpA;
        }
        
        if(i<b){
            tmpB = tmpB->next;
        }
        else{
            break;
        }
    }
    
    cout<< tmpA->val <<" "<< tmpB->val <<endl;
    tmpA->next = head2;
    tail2->next = tmpB;


    //print
    outputLinkedList(head1);
    
    
    return 0;
}