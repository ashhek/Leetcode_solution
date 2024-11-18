class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>res(n, 0);
        for(int i=0; i<n; ++i) {
            if(k < 0) {
              int sum = 0;
              for(int j = i-1; j>=i-abs(k); --j) {
                int original_ind = j;
                if(j<0) {
                    j += n;
                }
                sum += code[j];
                j = original_ind;
              }
              res[i] = sum;
            }
            if(k > 0) {
                int sum = 0;
                for(int j = i+1; j <= i+k; ++j) {
                    sum += code[j%n];
                }
                res[i] = sum;
            }
        }
        return res;
    }
};