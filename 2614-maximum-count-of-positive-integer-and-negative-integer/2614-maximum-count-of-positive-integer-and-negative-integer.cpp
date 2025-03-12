class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int posiLocation = -1;
        int negiLocation = -1;
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = (low + high) >> 1;

            if(nums[mid] > 0) {
                posiLocation = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(nums[mid] < 0) {
                negiLocation = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(posiLocation == -1 && negiLocation == -1) {
            return 0;
        }
        if(posiLocation == -1) {
            return negiLocation + 1;
        }
        if(negiLocation == -1) {
            return n - posiLocation;
        }
        return max(negiLocation+1, n - posiLocation);
    }
};