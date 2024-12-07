class Solution {
    bool help(vector<int>& nums, int opr, int x) {
        int cnt = 0;
        for (int num : nums) {
            if (num > x) {
                cnt += (num + x - 1) / x - 1; 
            }
            if (cnt > opr) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (help(nums, maxOperations, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};
