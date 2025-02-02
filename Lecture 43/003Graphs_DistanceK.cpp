/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // convert the tree into a undirected graph

        map<TreeNode*, vector<TreeNode*>> adj;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* front = q.front(); q.pop();
            if (front->left != NULL) {
                q.push(front->left);
                adj[front].push_back(front->left);
                adj[front->left].push_back(front);
            }
            if (front->right != NULL) {
                q.push(front->right);
                adj[front].push_back(front->right);
                adj[front->right].push_back(front);
            }
        }

        // 2. solve the SSSP for the graph you've built

        q.push(target); // target is our source

        map<TreeNode*, int> dm;
        dm[target] = 0;

        set<TreeNode*> vis;
        vis.insert(target);

        while (!q.empty()) {
            TreeNode* u = q.front(); q.pop();
            for (TreeNode* v : adj[u]) {
                if (vis.find(v) == vis.end()) {
                    vis.insert(v);
                    q.push(v);
                    dm[v] = dm[u] + 1;
                }
            }
        }

        vector<int> ans;
        for (auto [node, dist] : dm) {
            if (dist == k) {
                ans.push_back(node->val);
            }
        }

        return ans;



    }
};