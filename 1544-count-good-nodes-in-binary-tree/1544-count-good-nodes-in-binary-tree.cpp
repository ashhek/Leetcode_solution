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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, INT_MIN});
        int cnt = 0;

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int maxValue = q.front().second;
            q.pop();

            if(node->val >= maxValue) cnt++;
            maxValue = max(maxValue, node->val);

            if(node->left) q.push({node->left, maxValue});
            if(node->right)q.push({node->right, maxValue});
        }
        return cnt;
    }
};