class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;  // find predecessor of root
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right;
                // make root as right child of predecessor (temporary link)
                if(!pre -> right) {
                    pre -> right = root;
                    root = root -> left;                    
                }
                else {
                    pre -> right = nullptr;  // revert the changes - remove temporary link
                    // add to sum if node is left child and a leaf
                    if(pre == root -> left && !pre -> left) ans += pre -> val;
                    root = root -> right;
                }
            } 
			else root = root -> right;
        }
        return ans;
    }
};