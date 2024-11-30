/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(TreeNode* root) {
	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}
	return root->val;
}


int findMaximum(TreeNode* root) {
	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}
	return root->val;
}

// time : O(n.h)
// [HW] try to optimise this code from O(nh) to O(n)

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// 1. ask your friend to check if the leftSubtree is a BST

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST prop. works at the root

	bool rootIsBst = root->val > findMaximum(root->left) and
	                 root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and rootIsBst;

}

// time : O(n)

bool checkBSTUsingRanges(TreeNode* root, long long lb, long long ub) {

	if (root == NULL) {
		return true;
	}

	return root->val > lb and root->val < ub and
	       checkBSTUsingRanges(root->left, lb, root->val) and
	       checkBSTUsingRanges(root->right, root->val, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(12);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1; // LLONG_MIN
	long long ub = (long long)INT_MAX + 1; // LLONG_MAX

	checkBSTUsingRanges(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}