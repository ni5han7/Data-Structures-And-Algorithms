// Deleting A NODE of the given key using iterative method
#include <stdio.h>
#include <stdlib.h>

// Create a Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

// Push nodes at the front of the linked list to create a linked list in 4 steps:
void push(struct Node** head_ref, int new_data)
{
    // 1 Allocate the memory 
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    // 2. Insert the new data to the data of the new node:
    new_node->data= new_data;
    // 3. make the next of the new node to point to the head ref pointer:
    new_node->next= (*head_ref);
    // 4. change the head ref pointer to point to the new node:
    (*head_ref)= new_node;
}

// we have to keep note of the previous node of the node to be deleted and since we have to keep the
// head ref to traverse the linked list in future so we save the head ref in another pointer "temp"
void deleteNode(struct Node** head_ref, int key)
{
    //1 Store the pointer head ref in temp and create a node prev:
    struct Node *temp= *head_ref, *prev;

    //2 If the key is present in the head node then delete the head node and free the memory of the head node:
    if(temp!= NULL && temp->data== key){
    (*head_ref)= temp->next;
    free(temp);
    return;
    }

    //3 else traverse the linked list till we find the first occurence of the given key:
    while (temp!= NULL && temp->data!= key)
    {
        prev= temp;
        temp= temp->next;
    }
    
    //4 if the given key is not present and the traversing reaches the last node or temp == NULL then return
    if(temp == NULL)
    return;

    //5 else point the next of the prev node to the next of the temp node (current node, the node to be deletd) because
    // no condition is left to check rather than the node to be deleted now i.e., temp->data== key
    prev->next= temp->next;
    // 6 free memory
    free(temp);
    
    return;
}

// function to print the linked list
void printList(struct Node* node){
    printf("Linked List is: ");
    while (node!= NULL)
    {
        printf ("%d ", node->data);
        node=node->next;
    }
}

// Deiver function to perform the deletion
int main()
{
    // Create a head node
    struct Node* head= NULL;

    // Create a Linked List 3->4->5->1->7->8
    push(&head, 8);
    push(&head, 7);
    push(&head, 1);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    printList(head);

    // delete a node with key 5
    deleteNode(&head, 5);
    printf("Linked List after deleting a node is: ");
    printList(head);

    return 0;

}