class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr = nums;
        for(int num : nums) {
            arr.push_back(num);
        }

        for(int i=0; i<n; ++i) {
            if(is_sorted(arr.begin()+i, arr.begin()+i+n)) {
                return true;
            }
        }
        return false;
    }
};