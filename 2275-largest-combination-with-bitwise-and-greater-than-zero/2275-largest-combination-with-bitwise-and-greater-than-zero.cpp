class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int countPos[32] = {0};

        for(int num : candidates) {
            int pos = 0;
            while(num > 0) {
                if(num & 1) {
                    countPos[pos]++;
                }
                pos++;
                num = num >> 1;
            }
        }
        int res = 0;
        for(int i=0; i<32; ++i) {
            res = max(res, countPos[i]);
        }
        return res;
    }
};