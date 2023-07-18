class Solution {
public:
 // i + nums[i] => 3 1 3 4 1 1 1 5
    int jump(vector<int>& nums) {
        int currJumpInd = nums[0], maxJumpInd = nums[0];
        int n = nums.size();
        if(n==1) return 0;
        int minStep = 1;
        for(int i=1; i<n; i++){
            if(i>currJumpInd){
                ++minStep;
                currJumpInd = maxJumpInd;
            }
            maxJumpInd = max(maxJumpInd, i+nums[i]);
        }

        return minStep;
    }
};