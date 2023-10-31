class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<32; i++){
            int cnt = 0;
            for(auto it:nums){
                if(it & (1<<i))
                cnt++;
            }
            if(cnt>=k) sum += pow(2, i);
        }
        return sum;
    }
};