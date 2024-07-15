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
    TreeNode* dfs(int val,
                  unordered_map<int, vector<pair<int, int>>>& parentToChild) {
        auto node = new TreeNode(val);

        if (parentToChild.contains(val)) {
            for (auto& child_info : parentToChild[val]) {
                int child = child_info.first;
                int isLeft = child_info.second;

                if (isLeft) {
                    node->left = dfs(child, parentToChild);
                } else {
                    node->right = dfs(child, parentToChild);
                }
            }
        }
        return node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, int>>> parentToChild;
        unordered_set<int> allNodes;
        unordered_set<int> children;

        for (auto& des : descriptions) {
            int parent = des[0];
            int child = des[1];
            int isLeft = des[2];

            parentToChild[parent].push_back({child, isLeft});
            allNodes.insert(parent);
            allNodes.insert(child);
            children.insert(child);
        }
        int rootVal = 0;
        for (int node : allNodes) {
            if (!children.contains(node)) {
                rootVal = node;
                break;
            }
        }
        return dfs(rootVal, parentToChild);
    }
};