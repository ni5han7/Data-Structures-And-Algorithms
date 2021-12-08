#include <stdio.h>
#include <stdlib.h>

// Create A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};


// push function to create a Linked List by pushing nodes at the front
void push(struct Node** head_ref, int new_data)
{
    // 1. Create a new node Allocate the memory 
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));

    // 2. Put the new dat into the new node
    new_node->data= new_data;

    // 3. point the next of the new node to head node
    new_node->next= (*head_ref);

    // 4. chnage the head node
    (*head_ref)= new_node;
    
}

// function to delete the node at a given position
void deleteNodeAtPosition(struct Node **head_ref, int position)
{
    // If the linked list is empty
    if(*head_ref== NULL)
        return;

    // 1. store the head node and create a node named prev to keep the note of the previous of the node to be deleted
    struct Node* temp= *head_ref;

    // 2. if position == 0 then delete the head node
    if(position== 0)
    {
        (*head_ref)= temp->next;
        free(temp);
        return;
    }

    // 3. run a loop less than position-1 and untill the temp!= NULL 
    // Store the previous node of the node to bee deleted
    for (int i = 0; temp!= NULL &&  i < position-1; i++)
    {
        //this temp will be the previous node of the node to be deleted (if linked list is of some size)
        temp= temp->next;
    }
    
    // 4. if the position is more than the linked list size then return
    if(temp== NULL || temp->next== NULL)
        return;

    //5. Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // 6. Free the memory, the next of temp is the next of the previous node
    free(temp->next);

    // 7. change the next of the previous node to point to the next of next of the previous node
    temp->next= next;

    

}

void printList(struct Node* node)
{
    printf("Linked List is: ");
    while (node!= NULL)
    {
       printf("%d ", node->data);
       node= node->next;
    }
}

// Driver Function to run the program
int main()
{
    struct Node* head= NULL;
    
    // 3->5->2->7->4->8
    push(&head, 8);
    push(&head, 4);
    push(&head, 7);
    push(&head, 2);
    push(&head, 5);
    push(&head, 3);

    printList(head);
    deleteNodeAtPosition(&head, 4);
    printf("Linked List after deleting a node at the given position: ");
    printList(head);
    return 0;
}