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
private:
    int height(TreeNode* node, int& dim){
        if(node==NULL) return 0;

        int left = height(node->left, dim);
        int right = height(node->right, dim);

        dim = max(dim, left+right);
        return max(left, right)+1;
    }    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dim = 0;
        height(root, dim);
        return dim;
    }
};