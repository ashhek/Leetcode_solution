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
    bool isOk(TreeNode* l, TreeNode* r) {
        if(!l || !r) {
            return l==r;
        }

        if(l->val != r->val) return false;

        return isOk(l->left, r->right) && isOk(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root || isOk(root->left, root->right);
    }
};