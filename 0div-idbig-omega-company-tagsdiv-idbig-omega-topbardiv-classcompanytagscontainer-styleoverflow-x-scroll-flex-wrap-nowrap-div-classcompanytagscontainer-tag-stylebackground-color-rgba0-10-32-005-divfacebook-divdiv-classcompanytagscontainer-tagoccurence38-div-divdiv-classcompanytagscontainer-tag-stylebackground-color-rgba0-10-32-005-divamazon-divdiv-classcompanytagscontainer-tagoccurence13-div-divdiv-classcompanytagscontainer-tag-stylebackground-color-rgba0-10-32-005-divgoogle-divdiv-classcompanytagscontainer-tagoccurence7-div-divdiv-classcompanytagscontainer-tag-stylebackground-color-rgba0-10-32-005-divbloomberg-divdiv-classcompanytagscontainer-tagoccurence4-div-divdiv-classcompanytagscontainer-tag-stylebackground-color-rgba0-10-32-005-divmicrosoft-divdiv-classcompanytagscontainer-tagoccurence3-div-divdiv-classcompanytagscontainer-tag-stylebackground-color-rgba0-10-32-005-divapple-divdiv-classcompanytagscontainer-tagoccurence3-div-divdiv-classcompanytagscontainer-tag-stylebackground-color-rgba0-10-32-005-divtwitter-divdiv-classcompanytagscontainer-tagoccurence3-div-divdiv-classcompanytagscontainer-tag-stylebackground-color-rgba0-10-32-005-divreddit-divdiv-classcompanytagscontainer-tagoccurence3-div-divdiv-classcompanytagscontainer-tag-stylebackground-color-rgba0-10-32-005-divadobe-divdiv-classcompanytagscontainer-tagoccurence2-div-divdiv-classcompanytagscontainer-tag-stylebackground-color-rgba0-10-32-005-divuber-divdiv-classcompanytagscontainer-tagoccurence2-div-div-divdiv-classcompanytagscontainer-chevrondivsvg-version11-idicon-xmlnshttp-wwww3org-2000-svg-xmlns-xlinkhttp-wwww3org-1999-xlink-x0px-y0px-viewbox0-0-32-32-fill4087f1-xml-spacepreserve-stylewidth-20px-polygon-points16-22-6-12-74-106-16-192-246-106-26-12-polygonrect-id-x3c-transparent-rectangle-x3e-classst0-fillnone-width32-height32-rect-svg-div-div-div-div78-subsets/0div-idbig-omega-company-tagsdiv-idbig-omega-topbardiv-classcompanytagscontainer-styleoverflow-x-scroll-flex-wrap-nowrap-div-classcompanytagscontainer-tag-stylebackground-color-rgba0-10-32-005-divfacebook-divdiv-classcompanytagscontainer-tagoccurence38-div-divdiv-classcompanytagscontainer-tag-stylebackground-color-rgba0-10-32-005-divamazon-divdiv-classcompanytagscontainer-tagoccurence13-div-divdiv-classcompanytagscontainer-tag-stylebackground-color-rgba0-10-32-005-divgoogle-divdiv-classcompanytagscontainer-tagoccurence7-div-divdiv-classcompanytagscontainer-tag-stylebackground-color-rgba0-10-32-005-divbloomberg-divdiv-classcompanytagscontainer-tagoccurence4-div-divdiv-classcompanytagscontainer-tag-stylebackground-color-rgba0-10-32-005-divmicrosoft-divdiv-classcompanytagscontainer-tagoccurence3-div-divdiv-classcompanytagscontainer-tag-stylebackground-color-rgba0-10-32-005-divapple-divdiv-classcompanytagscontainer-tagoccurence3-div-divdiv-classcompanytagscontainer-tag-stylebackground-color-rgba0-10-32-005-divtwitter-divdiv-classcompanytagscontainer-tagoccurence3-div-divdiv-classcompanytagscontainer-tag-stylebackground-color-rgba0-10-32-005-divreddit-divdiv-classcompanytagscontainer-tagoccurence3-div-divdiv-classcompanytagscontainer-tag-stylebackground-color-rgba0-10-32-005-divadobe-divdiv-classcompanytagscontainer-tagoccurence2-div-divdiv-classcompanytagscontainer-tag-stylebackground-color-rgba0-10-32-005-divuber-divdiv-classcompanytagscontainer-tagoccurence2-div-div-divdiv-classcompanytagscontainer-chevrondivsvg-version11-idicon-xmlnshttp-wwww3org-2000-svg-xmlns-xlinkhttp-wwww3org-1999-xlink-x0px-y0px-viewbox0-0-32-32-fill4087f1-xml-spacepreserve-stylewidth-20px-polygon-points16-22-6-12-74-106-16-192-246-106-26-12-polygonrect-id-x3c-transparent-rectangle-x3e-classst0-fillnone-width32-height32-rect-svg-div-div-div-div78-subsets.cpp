class Solution {
    int n;
    void help(int i, vector<int>& nums, vector<int> temp,
              set<vector<int>>& st) {
        if (i == n) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        help(i + 1, nums, temp, st);
        temp.pop_back();
        help(i + 1, nums, temp, st);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        set<vector<int>> st;
        vector<int> temp;

        help(0, nums, temp, st);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};