#include <iostream>

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node* first (int d);
void addToEnd (Node** end, int d);

void printList (const Node* first) {
	// int

	// while ((next))
}

int main () {
	Node* beg = first(1);
	addToEnd(&beg, 10);



	return 0;
}

Node* first (int d) {
	Node* pv = new Node;
	pv -> data = d;
	pv -> prev = pv -> next = 0;

	return pv;
}

void addToEnd (Node** end, int d) {
	Node* node = new Node;
	node -> data = d;
	node -> prev = *end;
	node -> next = 0;
	(*end) -> next = node;
}