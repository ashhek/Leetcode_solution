class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>st;
        int len = 0;

        for(int i=0, j=0; j<nums.size(); ++j){
            st.insert(nums[j]);

            while(abs(*st.rbegin() - *st.begin()) > limit){
                st.erase(st.find(nums[i++]));
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};