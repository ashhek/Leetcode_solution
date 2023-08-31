class Solution {
    // int help(int n){
    //     int sum = 0;
    //     while(n!=0){
    //         sum += 
    //     }
    // }
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int d_sum = 0;
        
        for(auto it:nums) sum += it;
        
        for(int i=0; i<nums.size(); ++i){
            while(nums[i]!=0){
                d_sum += nums[i]%10;
                nums[i] = nums[i]/10;
            }
        }
        cout << d_sum << endl;
        return abs(sum-d_sum);
    }
};