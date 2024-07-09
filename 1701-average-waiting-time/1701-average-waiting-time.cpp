class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        int end = c[0][0];
        double ans = 0;

        for(auto i : c){
            int arr = i[0];
            int time = i[1];

            if(end<arr) end = arr;
            end += time;
            ans += double(end)  - double(arr);
        }
        ans /= (double)n;
        return ans;
    }
};