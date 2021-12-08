#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
// push node at the front of the list in 4 STEPS:
// Time Complexity is O(1)
void push(struct Node** head_ref, int new_data)
{
    // 1. Allocate the memory for the new node
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));

    // 2. Put in the data
    new_node->data= new_data;

    // 3. Point next of new node to the head node
    new_node->next= (*head_ref);

    // 4. make the head_ref as the Pointer of new_node
    (*head_ref)= new_node;
}

// Insert a node after a given Node in 5 STEPs:
// Time Complexity is O(1) as it takes the constant amount of time to the work
void insertAfter(struct Node* prev_node, int new_data)
{
    // 1. Check if the given node is NULL
    if(prev_node== NULL)
    {
    printf("the given node cannot be null");
    return;
    }

    // 2. Allocate the memory for the new node
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));

    // 3. Put in the data
    new_node->data= new_data;

    // 4. Make the next of new node as the Pointer of prev_node
    new_node->next= prev_node->next;

    // 5. Move the Pointer of prev_node to new node
    prev_node->next= new_node;
}

// Append a Node at the end of the list in 6 STEPS:
// Time Comlexity is O(n) as the link list is basically represented by the head node and append function traverses the 
// whole list of 'n' nodes till the last node. 
void append(struct Node** head_ref, int new_data)
{
    // 1. Allocate the memory for the new node
    struct Node* new_node= (struct Node*) malloc(sizeof(struct Node));
    struct Node* last= (*head_ref);

    // 2. Put in the data
    new_node->data= new_data;

      
    // 3. 
    new_node->next= NULL;

    // 4.
    if (*head_ref == NULL)
    {
        (*head_ref)= new_node;
        return;
    }
    

    // 5.
    while (last->next!= NULL)
    {
        last= last->next;
    }
    

    // 6.
    last->next= new_node;

    return;
}

void traverseNprint(struct Node* n)
{
    while(n!=NULL)
    {
        printf("%d \n", n->data);
        n= n->next;
    }
}

/*
int main()
{
    struct Node* head= NULL;
    push(&head, 2);
    insertAfter(head, 7);
    push(&head, 4);
    append(&head, 5);
    append(&head, 1);
    push(&head, 8);
    insertAfter(head->next, 9);
    printf("Created Linked List is:\n");
    traverseNprint(head); 

    return 0;
}
*/

