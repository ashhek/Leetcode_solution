class Solution {
    #define ll long long
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int left = 0;
        int cnt = 0;
        ll sum = 0;
        multiset<ll>mp;

        for(int right = 0; right<n; ++right) {
            sum += runningCosts[right];
            mp.insert(chargeTimes[right]);

            while(mp.size() && (*mp.rbegin() + ((right-left+1)*sum) > budget)) {
                sum -= runningCosts[left];
                auto it = mp.find(chargeTimes[left]);
                if(it != mp.end()) {
                    mp.erase(it);
                }
                left++;
            }
            if(mp.size())
            int cost = *mp.rbegin() + ((right-left+1)*sum);
            cnt = max(cnt, right-left+1);
        }
        return cnt;
    }
};