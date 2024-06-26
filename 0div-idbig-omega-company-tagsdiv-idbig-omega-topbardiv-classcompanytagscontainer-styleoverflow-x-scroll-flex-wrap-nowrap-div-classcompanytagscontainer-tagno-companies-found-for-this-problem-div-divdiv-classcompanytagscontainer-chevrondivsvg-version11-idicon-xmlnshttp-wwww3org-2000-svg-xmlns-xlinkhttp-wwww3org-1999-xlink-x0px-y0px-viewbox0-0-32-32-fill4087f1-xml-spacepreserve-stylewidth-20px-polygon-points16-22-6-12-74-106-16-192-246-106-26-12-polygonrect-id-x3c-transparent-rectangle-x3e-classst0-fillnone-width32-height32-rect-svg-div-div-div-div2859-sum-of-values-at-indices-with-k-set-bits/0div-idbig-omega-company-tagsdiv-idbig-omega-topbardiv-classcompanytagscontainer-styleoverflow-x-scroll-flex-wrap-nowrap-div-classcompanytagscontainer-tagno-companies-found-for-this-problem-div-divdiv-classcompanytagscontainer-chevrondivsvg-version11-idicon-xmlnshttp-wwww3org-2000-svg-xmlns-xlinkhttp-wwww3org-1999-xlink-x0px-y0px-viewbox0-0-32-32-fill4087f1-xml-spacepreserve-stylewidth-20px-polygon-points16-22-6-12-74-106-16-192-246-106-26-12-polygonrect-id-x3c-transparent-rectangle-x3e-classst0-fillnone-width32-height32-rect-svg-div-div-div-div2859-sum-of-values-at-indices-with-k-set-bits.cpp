class Solution {
    unsigned int countSetBits(unsigned int n){
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); ++i){
            if(countSetBits(i)==k){
                ans += nums[i];
            }
        }
        return ans;
    }
};