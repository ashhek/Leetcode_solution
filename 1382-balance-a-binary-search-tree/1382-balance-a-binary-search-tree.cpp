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
    vector<TreeNode*>sortedArr;

    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        sortedArr.push_back(root);
        inorder(root->right);
    }
    TreeNode* toBst(int start, int end){
        if(start>end) return NULL;

        int mid = (start+end)/2;
        TreeNode* root = sortedArr[mid];
        root->left = toBst(start, mid-1);
        root->right = toBst(mid+1, end);
        return root;
    }
public:
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return toBst(0, sortedArr.size()-1);
    }
};