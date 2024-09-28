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
    TreeNode* build(int& i, vector<int>&vec, int bound) {
        if(i == vec.size() || vec[i] > bound) return NULL;

        TreeNode* root = new TreeNode(vec[i++]);
        root->left = build(i, vec, root->val);
        root->right = build(i, vec, bound);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(i, preorder, INT_MAX);
    }
};