/*

Given the pre-order traversal of a binary tree, design a recursive algorithm to
compute the sum of TreeNodes inside the binary tree

Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 280
*/

#include<iostream>

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

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int sum = 0;

void dfs(TreeNode* root) {

	// base case

	if (root == NULL) {
		return;
	}

	// recursive case

	sum = sum + root->val;
	dfs(root->left);
	dfs(root->right);

}

// time : O(n)
// space: O(h) due to the function call-stack, where h is the height of the tree

int f(TreeNode* root) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	// find the sum of nodes of the given tree

	// 1. ask your friend to find the sum of nodes of the leftSubtree

	int x = f(root->left);

	// 2. ask your friend to find the sum of nodes of the rightSubtree

	int y = f(root->right);

	return x + y + root->val;

}

int main() {

	TreeNode* root = buildTree();

	dfs(root);

	cout << sum << endl;

	cout << f(root) << endl;

	return 0;
}