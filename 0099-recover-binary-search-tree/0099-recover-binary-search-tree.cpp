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
    void preorder(TreeNode* root, vector<int>&vec) {
        if(!root) return;

        vec.push_back(root->val);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
    int i = 0;
    void inorder(TreeNode* root, vector<int>&vec) {
        if(!root || i==vec.size()) return;

        inorder(root->left, vec);
        root->val = vec[i++];
        inorder(root->right, vec);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        vector<int>vec;
        preorder(root, vec);

        sort(vec.begin(), vec.end());
        inorder(root, vec);
    }
};