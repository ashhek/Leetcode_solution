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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int res = -1;
        int level = 0;
        long long maxSum = INT_MIN;
        while(!q.empty()) {
            int n = q.size();
            level++;
            long long sum = 0;
            for(int i=0; i<n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum > maxSum) {
                res = level;
                maxSum = sum;
            }
        }
        return res;
    }
};