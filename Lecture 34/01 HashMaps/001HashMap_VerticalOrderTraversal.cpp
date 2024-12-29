/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void dfs(node* root, map<int, vector<int>>& distMap, int d) {

	if (root == NULL) { // !root
		return;
	}

	distMap[d].push_back(root->data);
	dfs(root->left, distMap, d - 1);
	dfs(root->right, distMap, d + 1);

}

int main() {

	node* root = NULL;
	root = buildTree();

	map<int, vector<int>> distMap;

	dfs(root, distMap, 0);

	for (pair<int, vector<int>> p : distMap) {
		cout << p.first << " : ";
		for (int node : p.second) {
			cout << node << " ";
		}
		cout << endl;
	}


	return 0;
}

