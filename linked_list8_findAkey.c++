
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node= new Node();
    new_node->data= new_data;
    new_node->next= (*head_ref);
    (*head_ref)= new_node;
}
/*
//Iterative Method:
bool search(Node* head, int key)
{
    Node* current= head;
    while(current!= NULL)
    {
        if(current->data== key)
            return true;
        current= current->next;
    }
    return false;

}
*/

//Recursive Method:
bool search(Node* head, int key){
    //Base Case
    if(head== NULL)
        return false;
    // return true if the key is present in the current node
    if(head->data== key)
        return true;
    //recur the search funcion for the remaining nodes
    return search(head->next, key);

}

int main()
{
    Node* head= NULL;

    push(&head, 9);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);
    push(&head, 8);

    search(head, 7)? cout<<"Yes": cout<<"No";
    return 0;
}