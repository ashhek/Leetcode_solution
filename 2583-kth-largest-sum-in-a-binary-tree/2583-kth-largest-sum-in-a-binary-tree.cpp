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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        bool isLevel = false;
        
        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for(int i=0; i<n; ++i) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
            if(pq.size() == k) isLevel = true;
            while(pq.size() > k) {
                pq.pop();
            }
        }
        return isLevel ? pq.top() : -1;
    }
};