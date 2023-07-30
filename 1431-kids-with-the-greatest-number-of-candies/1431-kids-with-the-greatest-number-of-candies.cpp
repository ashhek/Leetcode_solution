class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        vector<bool>ans(n);

        for(int i=0; i<n; ++i){
            candies[i] += extraCandies;
            int mx = *max_element(candies.begin(), candies.end());
            if(candies[i]==mx) ans[i] = true;
            else false;
            candies[i] -= extraCandies;
        }
        return ans;
    }
};