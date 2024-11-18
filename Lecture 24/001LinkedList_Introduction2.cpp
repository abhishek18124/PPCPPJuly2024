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

ListNode* insertAtHead(ListNode* head, int val) { // head ptr is passed by val

	// insert a new node with the given val at the head of the LL

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
	return head;

}

int main() {

	ListNode* head = NULL; // LinkedList is empty

	head = insertAtHead(head, 50);
	head = insertAtHead(head, 40);
	head = insertAtHead(head, 30);
	head = insertAtHead(head, 20);
	head = insertAtHead(head, 10);

	printLinkedList(head);

	printLinkedList(head);

	return 0;
}