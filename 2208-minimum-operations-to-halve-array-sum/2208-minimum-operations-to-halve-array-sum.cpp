class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), (double)0);
        priority_queue<double>pq(nums.begin(), nums.end());
        int opr = 0;
        double totalSum = sum;

        while(true) {
            if(sum <= totalSum/2) break;
            double x = pq.top();
            pq.pop();
            sum -= x/2;
            opr++;
            pq.push(x/2);
        }
        return opr;

    }
};