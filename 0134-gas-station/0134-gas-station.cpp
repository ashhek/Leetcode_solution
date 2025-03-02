class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int earn = accumulate(gas.begin(), gas.end(), 0);
        int spent = accumulate(cost.begin(), cost.end(), 0);

        if(earn < spent) return -1;
        int idx = 0;

        int tank = 0;
        for(int i=0; i<n; ++i) {
            tank += gas[i] - cost[i];

            if(tank < 0) {
                tank = 0;
                idx = i+1;
            }
        }
        return idx;
    }
};