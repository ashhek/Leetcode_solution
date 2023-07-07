class Solution {
public:
    void helper(int n, int open, int close, string temp, vector<string>&ans){
        if(open==close && open == n){
            ans.push_back(temp);
        }
        if(close>open){
            return;
        }       
        if(open<n){
        helper(n, open+1, close, temp+"(", ans);
        }
        if(close<n)
        helper(n, open, close+1, temp+")", ans);
       return;     
    } 
    vector<string> generateParenthesis(int n) {
         vector<string> ans;
        helper(n, 0, 0, "",ans);
        return ans;     
    }
};