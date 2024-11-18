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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

ListNode* findMidPoint(ListNode* head) {

	if (head == NULL) {
		// LinkedList is empty
		return NULL;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

}

// steps = 3n/2 time : O(n)
// space : O(1)

bool isPalindrome(ListNode* head) {

	// 1. divide the linkedList around the midPoint
	ListNode* midPoint = findMidPoint(head);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. reverse the 2nd sublist
	head2 = reverseIterative(head2);

	// 3. compare the 1st sublist with the 2nd sublist
	while (head2 != NULL) {
		if (head->val != head2->val) {
			return false; // given LinkedList is not a palindrome
		}
		head = head->next;
		head2 = head2->next;
	}

	return true; // given LinkedList is a palindrome

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	isPalindrome(head) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}