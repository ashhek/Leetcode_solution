class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        multiset<int> st;
        int left = 0;
        vector<int> res;

        for (int right = 0; right < n; ++right) {
            if (nums[right] < 0) {
                st.insert(nums[right]);
            }

            if (right >= k) {
                if (nums[left] < 0) {
                    auto it = st.find(nums[left]);
                    if (it != st.end()) {
                        st.erase(it);
                    }
                }
                left++;
            }

            if (right >= k - 1) {
                if (st.size() < x) {
                    res.push_back(0);
                } else {
                    auto it = st.begin();
                    for(int i = 0; i < x-1; ++i) {
                        ++it;
                    }
                    res.push_back(*it);
                }
            }
        }
        return res;
    }
};
