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

void reverseSLL(Node* &head2, Node* tmp){
    if(tmp->next == NULL){
        head2 = tmp;
        return;
    }
    reverseSLL(head2, tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;
    
}

bool isPalindrome(Node* head, Node* head2){
    Node* tmp1 = head;
    Node* tmp2 = head2;
    bool flag = true;

    while(tmp1 != NULL){
        if(tmp1->val != tmp2->val){
            flag = false;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    } 

    return flag;
}

void copySLL(Node* head, Node* &head2, Node* &tail2){
    Node* tmp = head;
    while(tmp != NULL){
        inputLinkedList(head2, tail2, tmp->val);
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

    //create a copy list
    Node* head2 = NULL;
    Node* tail2 = NULL;
    copySLL(head, head2, tail2);

    //reverse the copy list
    reverseSLL(head2, head2);

    //edge case: if list has one element
    if(listSize(head)==1){
        cout<< "YES" <<endl;
        return 0;
    }

    //check palindrome
    (isPalindrome(head, head2))? std::cout<< "YES" <<endl : std::cout<< "NO" <<endl;
    
    return 0;
}