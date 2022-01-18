// C++ program to detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int detectLoop(Node* head)
{
	Node *slow_ptr = head, *fast_ptr = head;

	while (slow_ptr && fast_ptr && fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr) {
			return 1;
		}
	}
	return 0;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head->next;
	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	return 0;
}

 
