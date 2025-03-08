class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n;

        for(int i=0; i<=n-k; ++i){
            string s = blocks.substr(i, k);
            int cnt = 0;
            for(char ch : s){
                if(ch=='W') cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};