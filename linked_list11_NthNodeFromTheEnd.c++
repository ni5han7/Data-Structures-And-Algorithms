//Two pointer concept
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node= new Node;
    new_node->data= new_data;
    new_node->next= (*head_ref);
    (*head_ref)= new_node;
}

void nthNodeFromEnd(Node* head, int n){
    Node* main_ptr= head;
    Node* ref_ptr= head;

    int count= 0;
    if(head!= NULL){
        while(count< n){
            if(ref_ptr== NULL){
                printf("%d is greater than the number of nodes in the list", n);
                return;
            }
            ref_ptr= ref_ptr->next;
            count++;
        }

        if(ref_ptr== NULL){
            head= head->next;
            if(head!= NULL)
            printf("%drd Node from the end is: %d", n, main_ptr->data);
        }
        else{
            while(ref_ptr!= NULL){
                main_ptr= main_ptr->next;
                ref_ptr= ref_ptr->next;
            }
            printf("%drd Node from the end is: %d", n, main_ptr->data);
        }
    }
}

int main(){
    Node* head= NULL;
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);

    nthNodeFromEnd(head, 4);
}