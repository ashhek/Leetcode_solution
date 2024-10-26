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
    int dp1[100001];
    int dp2[100001];
    int maxH;
    void preOrder(TreeNode* root, int h) {
        if(!root) return;

        dp1[root->val] = maxH;
        maxH = max(maxH, h);

        preOrder(root->left, h+1);
        preOrder(root->right, h+1);

    }
     void reversePreOrder(TreeNode* root, int h) {
        if(!root) return;

        dp2[root->val] = maxH;
        maxH = max(maxH, h);

        reversePreOrder(root->right, h+1);
        reversePreOrder(root->left, h+1);

    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preOrder(root, 0);
        maxH = 0;
        reversePreOrder(root, 0);

        vector<int>res;

        for(auto q : queries) {
            res.push_back(max(dp1[q], dp2[q]));
        }
        return res;
    }
};