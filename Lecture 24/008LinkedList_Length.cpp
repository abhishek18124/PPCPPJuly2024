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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

// time : O(n)
// space: O(1)

int computeLengthIterative(ListNode* head) { // head ptr is passed by value

	int cnt = 0;

	while (head != NULL) {
		cnt++;
		head = head->next;
	}

	return cnt;

}

// time : O(n)
// space: O(n)

int computeLengthRecursive(ListNode* head) {

	// base case

	if (head == NULL) {
		// linkedList is empty
		return 0;
	}

	// recursive case

	// find the length of the given LL

	// 1. ask your friend to find the length of the sublist that starts from the node which comes after the head node

	int x = computeLengthRecursive(head->next);

	return 1 + x;

}

int main() {

	ListNode* head = NULL; // initially, linkedList empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	cout << computeLengthIterative(head) << endl;

	cout << computeLengthRecursive(head) << endl;

	return 0;
}