
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

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

int computeHeight(TreeNode* root) {

	// base case

	if (!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively, compute the height of the leftSubtree
	int x = computeHeight(root->left);

	// 2. recursively, compute the height of the rightSubtree
	int y = computeHeight(root->right);

	return 1 + max(x, y);

}

// time : O(n^2)

bool checkHeightBalanced(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	// 1. ask your friend to check if the LST is HB

	bool leftIsBal = checkHeightBalanced(root->left);

	// 2. ask your friend to check if the RST is HB

	bool rightIsBal = checkHeightBalanced(root->right);

	// 3. check if the HB prop. works at the root node

	bool rootIsBal = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and rootIsBal;

}

class Pair {

public:
	int height;
	bool isBal;
};

// time : O(n)

Pair checkHeightBalancedEfficient(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.isBal = true;
		p.height = -1;
		return p;
	}

	// recursive case

	// 1. ask your friend to check if the LST is HB and also find the height of the LST

	Pair left = checkHeightBalancedEfficient(root->left);

	// 2. ask your friend to check if the RST is HB and also find the height of the RST

	Pair right = checkHeightBalancedEfficient(root->right);

	// 3. check if the HB prop. works at the root node

	bool rootIsBal = abs(left.height - right.height) <= 1 ? true : false;

	p.height = 1 + max(left.height, right.height);
	p.isBal = left.isBal and right.isBal and rootIsBal;

	return p;

}

pair<int, bool> checkHeightBalancedEfficient2(TreeNode* root) { // first-height, second-isBal

	pair<int, bool> p;

	// base case

	if (root == NULL) {
		p.second = true;
		p.first = -1;
		return p;
	}

	// recursive case

	// 1. ask your friend to check if the LST is HB and also find the height of the LST

	pair<int, bool> left = checkHeightBalancedEfficient2(root->left);

	// 2. ask your friend to check if the RST is HB and also find the height of the RST

	pair<int, bool> right = checkHeightBalancedEfficient2(root->right);

	// 3. check if the HB prop. works at the root node

	bool rootIsBal = abs(left.first - right.first) <= 1 ? true : false;

	p.first = 1 + max(left.first, right.first);
	p.second = left.second and right.second and rootIsBal;

	return p;

}


int main() {

	TreeNode* root = buildTree();

	checkHeightBalanced(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	Pair p = checkHeightBalancedEfficient(root);

	p.isBal ? cout << "height-balanced" << endl : cout << "not height-balanced" << endl;

	pair<int, bool> p1 = checkHeightBalancedEfficient2(root);

	p1.second ? cout << "height-balanced" << endl : cout << "not height-balanced" << endl;

	return 0;
}