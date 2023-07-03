class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;

        map[0] = 1;
        int ans = 0, sum = 0, rem = 0;


        for(auto num:nums){
            sum += num;
            rem = sum % k;
            if(rem>=0){
                if(map.count(rem)){
                    ans += map[rem];
        
                }
                map[rem]++;
            }
            else{
                rem = rem+k;
                if(map.count(rem)){
                    ans += map[rem];
                }
                map[rem]++;
            }
        }
        return ans;
    }
};