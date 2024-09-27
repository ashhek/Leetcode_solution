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
    void preorder(TreeNode* node, long long currSum, int k, int& cnt,
                  unordered_map<long long, int>& unmap) {
        if (node == nullptr)
            return;

        // The current prefix sum
        currSum += node->val;

        // Here is the sum we're looking for
        if (currSum == k)
            cnt++;

        // The number of times the curr_sum − k has occurred
        // already, determines the number of times a path with
        // sum k has occurred up to the current node
        cnt += unmap[currSum - k];

        // Add the current sum into the hashmap
        // to use it during the child node's processing
        unmap[currSum]++;

        // Process the left subtree
        preorder(node->left, currSum, k, cnt, unmap);

        // Process the right subtree
        preorder(node->right, currSum, k, cnt, unmap);

        // Remove the current sum from the hashmap
        // in order not to use it during
        // the parallel subtree processing
        unmap[currSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> unmap;

        // To store the count of valid path
        int cnt = 0;
        preorder(root, 0LL, targetSum, cnt, unmap);
        return cnt;
    }
};