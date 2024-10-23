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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            bool isFoundx = false, isFoundy = false;
            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && node->right) {
                    if(node->left->val == x && node->right->val == y) return false;
                    if(node->left->val == y && node->right->val == x) return false;
                }
                if(node->left) {
                    if(node->left->val == x) isFoundx = true;
                    if(node->left->val == y) isFoundy = true;
                    q.push(node->left);
                }
                if(node->right) {
                    if(node->right->val == x) isFoundx = true;
                    if(node->right->val == y) isFoundy = true;
                    q.push(node->right);
                }
            }
            if(isFoundx && isFoundy) return true;
        }
        return false;
    }
};