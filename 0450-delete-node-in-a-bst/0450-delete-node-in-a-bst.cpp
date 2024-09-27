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
    TreeNode* findLastRight(TreeNode* node) {
        if(node->right == NULL) return node;

        return findLastRight(node->right);
    }
    TreeNode* helper(TreeNode* node) {
        if(node->right == NULL) return node->left;
        if(node->left == NULL) return node->right;

        auto rightChild = node->right;
        auto lastRight = findLastRight(node->left);

        lastRight->right = rightChild;

        return node->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* curr = root;
        if(root->val == key) return helper(root);

        while(curr) {
            if(curr->val > key) {
                if(curr->left && curr->left->val == key){
                    curr->left = helper(curr->left);
                }
                curr = curr->left;
            } else {
                if(curr->right && curr->right->val == key) {
                    curr->right = helper(curr->right);
                }
                curr = curr->right;
            }
        }
        return root;
    }
};