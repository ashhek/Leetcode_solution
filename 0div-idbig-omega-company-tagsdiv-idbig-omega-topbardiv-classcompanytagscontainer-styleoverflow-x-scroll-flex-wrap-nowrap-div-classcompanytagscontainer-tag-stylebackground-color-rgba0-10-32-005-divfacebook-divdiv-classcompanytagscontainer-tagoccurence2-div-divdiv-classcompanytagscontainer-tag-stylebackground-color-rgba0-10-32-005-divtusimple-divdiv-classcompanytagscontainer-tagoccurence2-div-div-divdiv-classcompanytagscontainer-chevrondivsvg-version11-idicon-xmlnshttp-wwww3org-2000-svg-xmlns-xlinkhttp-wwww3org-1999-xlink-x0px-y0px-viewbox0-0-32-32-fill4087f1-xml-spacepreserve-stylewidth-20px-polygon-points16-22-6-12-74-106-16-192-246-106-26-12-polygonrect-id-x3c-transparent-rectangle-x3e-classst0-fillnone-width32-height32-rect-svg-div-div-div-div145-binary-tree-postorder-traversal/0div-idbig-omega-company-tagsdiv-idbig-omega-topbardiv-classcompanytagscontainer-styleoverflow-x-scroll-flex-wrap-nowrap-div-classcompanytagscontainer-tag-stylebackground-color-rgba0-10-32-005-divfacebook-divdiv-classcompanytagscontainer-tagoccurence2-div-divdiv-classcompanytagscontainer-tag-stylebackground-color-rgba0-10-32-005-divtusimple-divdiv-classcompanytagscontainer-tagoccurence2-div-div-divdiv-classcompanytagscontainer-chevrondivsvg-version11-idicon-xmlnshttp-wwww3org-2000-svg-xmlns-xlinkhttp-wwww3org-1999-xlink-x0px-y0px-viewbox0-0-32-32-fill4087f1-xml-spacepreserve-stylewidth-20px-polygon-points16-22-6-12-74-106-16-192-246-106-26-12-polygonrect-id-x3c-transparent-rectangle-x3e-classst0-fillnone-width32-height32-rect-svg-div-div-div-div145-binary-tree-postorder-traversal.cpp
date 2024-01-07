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
    void help(TreeNode* node, vector<int>& ans){
        if(node==NULL) return;

        help(node->left, ans);
        help(node->right, ans);
        ans.push_back(node->val);
    }    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        help(root, ans);
        return ans;
    }
};