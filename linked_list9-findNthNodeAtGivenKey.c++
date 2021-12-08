#include <bits/stdc++.h>
#include <assert.h>
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
/*
//ITERATIVE METHOD:
int NthNode(Node* head, int index){
    Node* current= head;
    int count=0;
    while(current!=NULL){
        if(count==index){
            return current->data;
        }
        count++;
        current= current->next;
    }

    assert(0);
}
*/

//Recursive MEthod:
//In Recuersive method everything can be approached using head and the 0th Index but 
//head should point to the next node accordingly and the index should be decremented by 1 after each call of the function
int NthNode(Node* head, int index){
    if(head== NULL)
        return -1;
    if(index==0)
        return head->data;
    return NthNode(head->next, index-1);
}

int main(){
    Node* head= NULL;

    push(&head, 7);
    push(&head, 7);
    push(&head, 0);
    push(&head, 1);
    push(&head, 7);
    push(&head, 7);

    cout<< "Element at index 3 is:\n" <<NthNode(head, 2);
    return 0;
}