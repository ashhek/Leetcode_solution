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
    int cnt = 0;
    void countGoodNode(TreeNode* root, int mx) {
        if (!root)
            return;

        if (root->val >= mx)
            cnt++;

        mx = max(mx, root->val);

        countGoodNode(root->left, mx);
        countGoodNode(root->right, mx);
    }

public:
    int goodNodes(TreeNode* root) {
        countGoodNode(root, INT_MIN);
        return cnt;
    }
};