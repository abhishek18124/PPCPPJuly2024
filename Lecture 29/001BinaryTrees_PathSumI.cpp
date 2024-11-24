#include<iostream>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

// time : O(n)
// space: O(h) due to function call-stack

bool hasPathSum(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return false;
	}

	if (root->left == NULL and root->right == NULL) {
		// you are at the leaf node
		if (root->val == targetSum) {
			// you've found a root-to-leaf path in the given tree whose sum is equal to targetSum
			return true;
		}
		return false;
	}

	// recursive case

	// check if there is a root-to-leaf path in the given tree whose sum is equal to targetSum

	// // 1. ask your friend to check in the LST if there is a root-to-leaf whose sum is equal to targetSum-root->val

	// bool X = hasPathSum(root->left, targetSum - root->val);

	// // 2. ask your friend to check in the RST if there is a root-to-leaf whose sum is equal to targetSum-root->val

	// bool Y = hasPathSum(root->right, targetSum - root->val);

	// return X or Y;

	return hasPathSum(root->left, targetSum - root->val) or
	       hasPathSum(root->right, targetSum - root->val);

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 30;

	hasPathSum(root, targetSum) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}