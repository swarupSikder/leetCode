//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode(int val){
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

void inputLinkedList(ListNode* &head, ListNode* &tail, int val){
    //create a new node first
    ListNode* newNode = new ListNode(val);

    //edge case: if list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    //list is not empty
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int listSize(ListNode* head){
    int i=0;
    ListNode* tmp = head;
    while(tmp != NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}

void outputLinkedList(ListNode* head){
    if(head == NULL){
        cout<< "" <<endl;
        return;
    }

    ListNode* tmp = head;
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
    ListNode* head = NULL;
    ListNode* tail = NULL;

    int val;
    while(1){
        cin>> val;
        if(val == -1){
            break;
        }
        inputLinkedList(head, tail, val);
    }

    //swap the head & head_next
    ListNode* tmp = head;
    head = head->next;
    tmp->next = head->next;
    tmp->prev = head;
    head->next = tmp;
    head->prev = NULL;

    //move the Node after the pair
    tmp = tmp->next;
    ListNode* tmp2 = tmp;

    cout<< tmp->val <<endl;
    cout<< tmp2->next->val <<endl;

    //swap pair
        // tmp->next = tmp2->next;     //task 1
        // tmp2->next = tmp;           //task 2
        // tmp2->prev = tmp->prev;     //task 3
        // tmp->prev = tmp2;           //task 4
        // tmp2->prev->next = tmp2;    //task 5
        // tmp->next->prev = tmp;      //task 6

    // while(tmp2!=NULL && tmp2->next !=NULL){
    //     //swap pair
    //     tmp->next = tmp2->next;     //task 1
    //     tmp2->next = tmp;           //task 2
    //     tmp2->prev = tmp->prev;     //task 3
    //     tmp->prev = tmp2;           //task 4
    //     tmp2->prev->next = tmp2;    //task 5
    //     tmp->next->prev = tmp;      //task 6
    // }
    


    //print
    outputLinkedList(head);
    
    
    return 0;
}