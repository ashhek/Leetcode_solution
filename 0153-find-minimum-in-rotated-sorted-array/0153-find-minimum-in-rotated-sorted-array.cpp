class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0, end = n-1;

        while(start<=end){
            int mid = end + (start-end)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;

            if(nums[start]<=nums[end]) return nums[start];

            else if(nums[prev]>=nums[mid] && nums[next]>=nums[mid]){
                return nums[mid];
            }

            else if(nums[mid]>=nums[start]) start = mid + 1;
            else if(nums[mid]<=nums[end]) end = mid - 1;
        }
        return 0;
    }
};