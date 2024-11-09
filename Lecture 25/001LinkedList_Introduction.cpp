#include<iostream>

using namespace std;

class ListNode {

public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void printLinkedList(ListNode* head) { // head ptr is passed by value

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

void insertAtHead(ListNode*& headRef, int val) { // head ptr is passed by ref

	// insert a new node with the given val at the head of the LL

	ListNode* n = new ListNode(val);
	n->next = headRef;
	headRef = n;

}

int main() {

	// ListNode* n = new ListNode(10);

	// cout << n->val << " " << (*n).val << endl;

	// if (n->next == NULL) {
	// 	cout << "n->next is equal to NULL" << endl;
	// }

	ListNode* head = NULL; // LinkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) cout << "LinkedList is empty" << endl;

	printLinkedList(head);

	printLinkedList(head);

	return 0;
}