#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node* next;
};

void deleteList(struct Node** head_ref){
    struct Node* current= *head_ref;
    struct Node* next;
    while (current!= NULL)
    {
        next= current->next;
        free(current);
        current= next;
    }
    
    *head_ref= NULL;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data= new_data;
    new_node->next= *head_ref;
    (*head_ref)= new_node;
}

void printList(struct Node* node){
    while(node!= NULL){
        printf(" %d ", node->data);
        node= node->next;
    }

}

int main(){
    struct Node* head= NULL;

    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    printf("Linked List created:\n");
    printList(head); 
    deleteList(&head);// will change the head to point to NULL when the deletion is completed
    printf("Deleted Linked List:\n");
    printList(head);// head is now pointing to NULL
    printf("Linked List deleted.\n");

    return 0;
}