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
    TreeNode* curr;
    unordered_map<TreeNode*, TreeNode*>par;
    void findP(TreeNode* root, int start) {
        if(!root) return;
        if(root->val == start) curr = root;
        if(root->left) {
            par[root->left] = root;
            findP(root->left, start);
        }
        if(root->right) {
            par[root->right] = root;
            findP(root->right, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        findP(root, start);
        queue<TreeNode*>q;
        int time = 0;
        q.push(curr);
        unordered_set<TreeNode*>st;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* node = q.front();
                st.insert(node);
                q.pop();
                if(node->left && !st.count(node->left)) q.push(node->left);
                if(node->right && !st.count(node->right)) q.push(node->right);
                if(st.find(par[node]) == st.end() && par[node]) {
                    q.push(par[node]);
                }
            }
            time++;
        }
        return time - 1;
    }
};