#include <stdio.h>
#include <stdlib.h>
#include "linked_list3_insertion.c"


void printMiddle(struct Node* head){
    struct Node* slow_ptr= head;
    struct Node* fast_ptr= head;

    if(head!= NULL){
        while(fast_ptr!= NULL && fast_ptr->next!= NULL){
            slow_ptr= slow_ptr->next;
            fast_ptr= fast_ptr->next->next;
        }
        printf("%d is the middle node\n\n", slow_ptr->data);
    }
}

void printList(struct Node* ptr){
    while (ptr!= NULL)
    {
        printf("%d->", ptr->data);
        ptr= ptr->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head= NULL;
    int i;
    for(i=5; i>0; i--){
        push(&head, i);
        printList(head);
        printMiddle(head);
    }
    return 0;
}