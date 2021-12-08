
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node= new Node();
    new_node->data= new_data;
    new_node->next= (*head_ref);
    (*head_ref)= new_node;
}

/*
ITERATIVE METHOD:
int getCount(Node* head)
{
    int count= 0;
    Node* current= head;
    while (current!= NULL)
    {
        count++;
        current= current->next;
    }
    return count;
}
*/

// RECURSIVE METHOD:
int getCount(Node* head)
{
    if(head== NULL)
        return 0;
    else 
        return 1+ getCount(head->next); 
}
int main()
{
    Node* head= NULL;

    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    

    cout<< "Count Of Node Is:\n" <<getCount(head);
    return 0;
}

