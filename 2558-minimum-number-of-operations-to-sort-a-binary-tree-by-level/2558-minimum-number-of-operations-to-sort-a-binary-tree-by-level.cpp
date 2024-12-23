/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int minSwap(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        vector<int> target = nums;
        sort(target.begin(), target.end());

        int swap = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (target[i] != nums[i]) {
                swap++;
                int curPos = mp[target[i]];
                mp[nums[i]] = curPos;
                std::swap(nums[curPos], nums[i]);
            }
        }
        return swap;
    }

public:
    int minimumOperations(TreeNode* root) {
        int ind = root->val;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            cnt += minSwap(level);
        }
        return cnt;
    }
};