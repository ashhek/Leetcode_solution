class Solution {
public:
    int k;
    int res;
    void help(int ind, vector<int>& nums, unordered_map<int, int>& mp) {
        if (ind >= nums.size()) {
            res++;
            return;
        }
        help(ind + 1, nums, mp);

        if (!mp[nums[ind] - k] and !mp[nums[ind] + k]) {

            mp[nums[ind]]++;
            help(ind + 1, nums, mp);
            mp[nums[ind]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int p) {
        res = 0;
        k = p;

        unordered_map<int, int> mp;

        help(0, nums, mp);
        return res - 1;
    }
};