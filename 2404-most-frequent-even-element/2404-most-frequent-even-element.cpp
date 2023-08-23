class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>m;

        for(auto it:nums) m[it]++;

        int ans = -1;
        int maxFreq = 0;

        for(auto it:m){
            if(it.second>maxFreq and (it.first%2==0 || it.first==0)){
                ans = it.first;
                maxFreq = it.second;
            }
        }
        return ans;
    }
};