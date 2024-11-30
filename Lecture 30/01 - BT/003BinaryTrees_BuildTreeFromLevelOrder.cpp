/*

given the level order traversal of a binary tree, design an algorithm to construct a
binary tree from it.

Example
	Input: 10 20 30 40 50 -1 60 -1 -1 70 -1 -1 -1 -1 -1
*/

#include<iostream>
#include<queue>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* buildTree() {

	int val;
	cin >> val;

	TreeNode* root = new TreeNode(val);
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* front = q.front();
		q.pop();

		// buld the left and the right child for the front node
		int leftVal;
		cin >> leftVal;
		if (leftVal != -1) {
			// front node has a leftChild
			TreeNode* leftChild = new TreeNode(leftVal);
			front->left = leftChild;
			q.push(leftChild);
		}
		int rightVal;
		cin >> rightVal;
		if (rightVal != -1) {
			// front node has a rightChild
			TreeNode* rightChild = new TreeNode(rightVal);
			front->right = rightChild;
			q.push(rightChild);
		}
	}

	return root;

}

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}

}


int main() {

	TreeNode* root = buildTree();
	printLevelOrder(root);

	return 0;
}