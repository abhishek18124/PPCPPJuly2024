#include<iostream>
#include<vector>

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

class Triple {
public :

	int numCameras;
	bool isCovered;
	bool hasCamera;

};

Triple dfs(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {
		t.numCameras = 0;
		t.hasCamera = false;
		t.isCovered = true;
		return t;
	}

	// recursive case

	Triple left = dfs(root->left);
	Triple right = dfs(root->right);

	// decide for the root node

	// option 1 : install camera at the root

	if (!left.isCovered || !right.isCovered) {

		// you've to install camera at the root

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.hasCamera = true;
		t.isCovered = true;

		return t;

	}

	// option 2 : donot install camera at the root

	t.numCameras = left.numCameras + right.numCameras;
	t.hasCamera = false;
	t.isCovered = left.hasCamera || right.hasCamera ? true : false;

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = dfs(root);
	if (!t.isCovered) return t.numCameras + 1;
	return t.numCameras;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	return 0;
}