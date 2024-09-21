class Solution {
public:

        vector<string> ans;
        vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string digits, string temp, int i, int n){
       if(i==n){
           ans.push_back(temp);
           return;
       } 

       int digit = digits[i]-'0';
        for(char ch : keys[digit]) {
            temp.push_back(ch);
            helper(digits, temp, i+1, n);
            temp.pop_back();


        }
    }

    vector<string> letterCombinations(string digits) {
      
       int n = digits.size();
       if(n==0) return ans;
    
        helper(digits, "", 0, n);
        return ans;
    }
};