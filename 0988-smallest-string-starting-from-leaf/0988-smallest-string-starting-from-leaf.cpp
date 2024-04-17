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
    void help(TreeNode* root, vector<string>&v, string temp){
        if(!root)
        return;

        int ch = root->val + 97;
        temp += char(ch);

        if(!root->left and !root->right){
            reverse(temp.begin(), temp.end());
            v.push_back(temp);
        }
        help(root->left, v, temp);
        help(root->right, v, temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>v;
        help(root, v, "");
       
       sort(v.begin(), v.end());
       return v[0];

        
    }
};