class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());

        while(!pq.empty() && k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x-x/2);
        }
        int ans = 0;
        while(!pq.empty()) {
            cout << pq.top() << endl;
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};