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
// time : O(m+n) where m and n are the length of the 1st and 2nd linkedList respectively
ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy;

	while (head1 != NULL and head2 != NULL) {
		if (head1->val < head2->val) {
			// next node is head1
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		} else {
			// next node is head2
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}

	if (head2 != NULL) {
		temp->next = head2;
	}

	if (head1 != NULL) {
		temp->next = head1;
	}

	return dummy->next;

}

int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 50);
	insertAtHead(head1, 30);
	insertAtHead(head1, 10);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 60);
	insertAtHead(head2, 40);
	insertAtHead(head2, 20);

	printLinkedList(head2);

	ListNode* head = mergeSortedLinkedList(head1, head2);

	printLinkedList(head);

	return 0;
}