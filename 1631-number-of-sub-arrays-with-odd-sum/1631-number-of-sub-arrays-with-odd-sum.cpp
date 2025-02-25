class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int preffSum = 0;
        int odd = 0, even = 1;
        int cnt = 0;

        for(int num : arr) {
            preffSum += num;
            if(preffSum % 2) {
                cnt += even;
                odd++;
            } else {
                cnt += odd;
                even++;
            }
            cnt = (cnt%mod);
        }
        return cnt;
    }
};