class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<int>st;
        int prev = -1;
        for(int num : nums) {
            int minLimit = num - k;
            int maxLimit = num + k;

            if(st.find(minLimit) == st.end()) {
                st.insert(minLimit);
                prev = minLimit;
            } else {
                if(prev + 1 <= maxLimit) {
                    st.insert(prev+1);
                    prev = prev + 1;
                } else {
                    st.insert(num);
                }
            }
        }
        return st.size();
        
    }
};