/*

given the pre-order traversal of a binary tree, output its level-order traversal.

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 20 30 40 50 60 70
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

	// 1. read the val of the root TreeNode
	int val;
	cin >> val;

	if (val == -1) {
		// construct an empty tree and return the pointer to its root
		return NULL;
	}

	// 2. construct the root TreeNode
	TreeNode* root = new TreeNode(val);

	// 3. read the preOrder traversal of the leftSubtree & build the leftSubtree
	root->left = buildTree();

	// 4. read the preOrder traversal of the rightSubtree & build the rightSubtree
	root->right = buildTree();

	return root;

}

// time : O(n)
// space: n/2 if tree is perfect due to queue ~ O(n)

void printLevelOrder(TreeNode* root) {

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode* front = q.front();
		q.pop();

		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			// process the front node
			cout << front->val << " ";
			if (front->left != NULL) {
				q.push(front->left);
			}
			if (front->right != NULL) {
				q.push(front->right);
			}
		}
	}

}

// time : O(n)
// space: O(n) due to queue

void printLevelOrder2(TreeNode* root) {

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		int qsize = q.size();

		while (q.size--) { // this loop runs qsize times // qsize represents no. of nodes at the current level

			TreeNode* front = q.front();
			q.pop();

			// process the front node

			cout << front->val << " ";
			if (front->left != NULL) {
				// visit the left child of front node
				q.push(front->left);
			}

			if (front->right != NULL) {
				// visit the right child of the front node
				q.push(front->right);
			}

		}

		cout << endl;

	}

}

int main() {

	TreeNode* root = buildTree();

	printLevelOrder(root);

	printLevelOrder2(root);

	return 0;
}