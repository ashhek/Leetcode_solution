class Solution {
    #define pp pair<int,int>
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
       priority_queue<pp, vector<pp>, greater<pp>>pq;
       for(int i=0; i<n; ++i) {
        pq.push({nums[i], i});
       }
       while(k--) {
        int ele = pq.top().first;
        int ind = pq.top().second;
        pq.pop();

        nums[ind] = ele * multiplier;
        pq.push({nums[ind], ind});
       }
       return nums;
    }
};