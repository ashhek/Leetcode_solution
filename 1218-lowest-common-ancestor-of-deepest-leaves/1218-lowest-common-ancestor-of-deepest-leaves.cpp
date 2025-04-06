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
    unordered_map<TreeNode*, int> depth;
    int findingDepth(TreeNode* root) {
        if (!root)
            return 0;

        if (depth.find(root) != depth.end())
            return depth[root];

        return depth[root] =
            1 + max(findingDepth(root->left), findingDepth(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findingDepth(root);

        if(!root) return nullptr;

        int l = depth[root->left];
        int r = depth[root->right];

        if(l == r) {
            return root;
        }
        if(l > r) {
            return lcaDeepestLeaves(root->left);
        }
        else {
            return lcaDeepestLeaves(root->right);
        }
    }
};