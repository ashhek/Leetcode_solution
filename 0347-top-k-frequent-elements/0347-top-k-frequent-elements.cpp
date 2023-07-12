class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>m;
        vector<int> ans;
        for(auto num:nums) m[num]++;
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minh;
        for(auto it:m){
            minh.push({it.second, it.first});
            if(minh.size()>k) minh.pop();
        }
        while(minh.size()>0){
           ans.push_back(minh.top().second);
           minh.pop();
        }
        return ans;
        
    }
};