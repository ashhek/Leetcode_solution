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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return root;

        vector<int> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sum = 0;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelSum.push_back(sum);
        }
        // for(int i : levelSum) cout << i << " " << endl;
        q.push(root);
        root->val = 0;
        int i = 1;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                int siblingSum = node->left ? node->left->val : 0;
                siblingSum += node->right ? node->right->val : 0;

                if (node->left) {
                    node->left->val = levelSum[i] - siblingSum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum[i] - siblingSum;
                    q.push(node->right);
                }
            }
            i++;
        }
        return root;
    }
};