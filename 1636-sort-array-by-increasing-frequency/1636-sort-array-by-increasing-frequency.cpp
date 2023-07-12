class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minh;
        priority_queue<pair<int,int>> maxh;
        unordered_map<int,int>m;
        vector<int>ans;

        for(auto num:nums) m[num]++;

        for(auto it:m){
            maxh.push({-it.second, it.first});
        }
        while(maxh.size()>0){
            for(int i=0; i<abs(maxh.top().first); ++i){
            ans.push_back(maxh.top().second); 
            }
            maxh.pop();
        }
       
       return ans;
    }
};