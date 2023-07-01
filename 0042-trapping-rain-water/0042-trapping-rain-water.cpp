class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int left = 0, right = n-1;
        long long int ans = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                leftMax = max(height[left], leftMax);
                ans += (leftMax -  height[left]);
                left++;
            }
            else {
                rightMax = max(height[right], rightMax);
                ans += (rightMax - height[right]);
                right--;
            }
        }
        return ans;

    }
};