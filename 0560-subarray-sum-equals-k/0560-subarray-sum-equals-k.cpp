class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        if(n==0) return 0;
        unordered_map<int,int>m;  
        int currentSum = 0, ans = 0;
        for(int i=0; i<n; ++i){
            currentSum += nums[i];
            if(currentSum==k) ans++;
            if(m.find(currentSum-k)!= m.end()) ans += m[currentSum-k];
            m[currentSum]++;
        }
        return ans;
    }
};