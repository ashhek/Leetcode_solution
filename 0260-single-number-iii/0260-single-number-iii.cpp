class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor_r = 0;
        
        for(int& num:nums){
            Xor_r ^= num;
        }
        //rightmost bit set niklne ke liye 
        int mask = (Xor_r) & (-Xor_r);

        int grp1 = 0;
        int grp2 = 0;
        
        for(int& num:nums){
            if(mask & num){
                grp1 ^= num;
            } else{
                grp2 ^= num;
            }
        }
        return {grp1, grp2};
    }
};