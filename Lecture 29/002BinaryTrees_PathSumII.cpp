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

void printPath(const vector<int>& path) {
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
	cout << endl;
}

void dfs(TreeNode* root, int targetSum, vector<int>& path) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		// you are at the leaf node
		if (root->val == targetSum) {
			// you've found a valid path
			path.push_back(root->val);
			printPath(path);
			path.pop_back();
		}
		return;
	}

	// recursive case

	path.push_back(root->val);
	dfs(root->left, targetSum - root->val, path);
	dfs(root->right, targetSum - root->val, path);
	path.pop_back(); // backtracking

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
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	vector<int> path;

	dfs(root, targetSum, path);

	return 0;
}