class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0; long long sum2 =0; long long cnt = 0; long long cnt2 = 0;
        
        for(auto it:nums1){
            if(it==0) cnt++;
            sum1 += it;
        }
         for(auto it:nums2){
            if(it==0) cnt2++;
            sum2 += it;
        }
        if(cnt==0 and sum1<sum2+cnt2) return -1;
        if(cnt2==0 and sum2<sum1+cnt) return -1;
        return max(sum1+cnt, sum2+cnt2);
        
    }
};