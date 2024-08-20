class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st;

        int ind = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                nge[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        int m = nums1.size();
        unordered_map<int,int>mp;
        for(int num : nums1) {
            mp[num] = -1;
        }
        for(int i=0; i<n; ++i) {
            if(mp.find(nums2[i]) != mp.end()) {
                mp[nums2[i]] = nge[i];
            }
        }
        vector<int>res(m);
        for(int i=0; i<m; ++i) {
            res[i] = mp[nums1[i]]; 
        }
        
        return res;
    }
};