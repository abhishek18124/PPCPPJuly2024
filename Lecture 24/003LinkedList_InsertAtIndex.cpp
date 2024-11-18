#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getNode(ListNode* temp, int j) { // head ptr is passed by value
	// find the address of the node at index j of the given linkedList
	while (j-- and temp != NULL) { // this loop runs exactly j times
		temp = temp->next;
	}
	return temp;
}

// time : O(n)

void insertAtIndex(ListNode*& head, int i, int val) { // head ptr is passed by value

	if (i == 0) {
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val); // const
	ListNode* prev = getNode(head, i - 1); // linear
	if (prev == NULL) {
		// i > n i.e. i is invalid
		return;
	}
	n->next = prev->next; // const
	prev->next = n; // const

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	insertAtIndex(head, 0, 35);

	printLinkedList(head);

	return 0;
}