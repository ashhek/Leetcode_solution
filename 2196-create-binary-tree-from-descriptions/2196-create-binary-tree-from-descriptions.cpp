/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> adj;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (!adj.contains(parent)) {
                adj[parent] = new TreeNode(parent);
            }
            if (!adj.contains(child)) {
                adj[child] = new TreeNode(child);
            }

            if (isLeft) {
                adj[parent]->left = adj[child];
            } else {
                adj[parent]->right = adj[child];
            }
            children.insert(child);
        }
        for (auto& it : adj) {
            auto val = it.first;
            auto node = it.second;

            if (!children.contains(val))
                return node;
        }
        return NULL;
    }
};