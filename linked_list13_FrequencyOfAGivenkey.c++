//Recursive method
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

//with a Global VAriable
/*
ALGORITHM:
Declare and initialise a Global variable 'frequency' with 0

count(head, key)
if head== NULL
return frequency;  //Base Case
if head->data= key
frequency++;       //Increment the frequency
return count(head->next, key)  //Recur the function for the remaining nodes
*/
/*
int frequency= 0;

int count(Node* head, int key){
    if (head== NULL)
        return frequency;
    if(head->data== key)
        frequency++;
    return count(head->next, key);
}
*/
int count(struct Node* head, int key)
{
    if (head == NULL)
        return 0;
    if (head->data == key)
        return 1 + count(head->next, key);
    return count(head->next, key);
}


int main(){
    Node* head= NULL;

    int i;
    for(i=5; i>0; i--){
        if(i>2)
            push(&head, 1);
        else
            push(&head, 2);
    }
    cout<< "Frequency of 2 is " << count(head, 2);
    return 0;
}
