class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int ans = 0;
        int left = 0;
        for(int right=0; right<n; ++right){
            if(!set.count(s[right])){
               set.insert(s[right]);
               ans = max(ans, right-left+1);
            }
            else{
                while(set.count(s[right])){
                   set.erase(s[left]);
                   left++;
                }
            }
            set.insert(s[right]);
        }
        return ans;
    }
};