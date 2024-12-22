/*

    Given k sorted linked list, merge them and print the sorted output.

    k = 3
    Input : 1->3->5
            2->4->6
            0->8->7

    Output: 0->1->2->3->4->5->6->7->8

*/

#include<iostream>
#include<queue>
#include<vector>

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

class ListNodeCmp {

public:

    // return false if you want a to be given higher priority than b

    bool operator()(ListNode* a, ListNode* b) {
        if (a->val < b->val) {
            // we want a to be given more priority than b
            return false;
        }
        return true;
    }

};

// time : O(nklogk)
// space : O(k) due to minHeap, at any point of time, there will be only one node from a linkedlist in the heap

ListNode* mergeKSortedLinkedList(vector<ListNode*> v) {

    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> minHeap(v.begin(), v.end());
    // for (int i = 0; i < v.size(); i++) {
    //     minHeap.push(v[i]);
    // }

    while (!minHeap.empty()) {
        ListNode* minNode = minHeap.top();
        minHeap.pop();

        temp->next = minNode;
        temp = temp->next;

        if (minNode->next != NULL) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;

}

int main() {

    ListNode* head1 = NULL;

    insertAtHead(head1, 7);
    insertAtHead(head1, 4);
    insertAtHead(head1, 1);

    printLinkedList(head1);

    ListNode* head2 = NULL;

    insertAtHead(head2, 8);
    insertAtHead(head2, 5);
    insertAtHead(head2, 2);

    printLinkedList(head2);

    ListNode* head3 = NULL;

    insertAtHead(head3, 9);
    insertAtHead(head3, 6);
    insertAtHead(head3, 3);

    printLinkedList(head3);

    vector<ListNode*> v = {head1, head2, head3};

    ListNode* head = mergeKSortedLinkedList(v);

    printLinkedList(head);

    return 0;
}
