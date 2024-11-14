class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, -1);
        stack<int>st;

        for(int i=0; i<2*n; ++i) {
            while(!st.empty() && nums[st.top()%n] < nums[i%n]) {
                res[st.top()%n] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};