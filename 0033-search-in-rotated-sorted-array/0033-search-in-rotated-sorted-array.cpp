class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    
    
        int answer = helper(nums, 0, left - 1, target);
        if (answer != -1) {
            return answer;
        }
        
    
        return helper(nums, left, n - 1, target);
    }
    
     int helper(vector<int> nums, int leftb, int rightb, int target) {
        int left = leftb, right = rightb;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};