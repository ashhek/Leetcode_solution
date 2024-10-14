class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long opr = 0;
        priority_queue<long long, vector<long long>, greater<long long>>pq(nums.begin(), nums.end());
        
        while(true) {
            if(pq.top() >= k) break;

            opr++;

            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            long long p = min(x, y)*2 + max(x, y);
            pq.push(p);
        }
        return opr;
    }
};