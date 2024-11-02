/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int help(TreeNode* root) {
        if(!root) return 0;

        int leftSum = max(0, help(root->left));
        int rightSum = max(0, help(root->right));

        maxSum = max(maxSum, leftSum + rightSum + root->val);

        return max(leftSum, rightSum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        help(root);
        return maxSum;
    }
};