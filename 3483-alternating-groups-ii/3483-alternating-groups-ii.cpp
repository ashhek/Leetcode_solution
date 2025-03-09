class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size();
        int cnt = 1;

        for(int i=1; i<n-1+k; ++i){
            if(colors[i%n] != colors[(n+i-1)%n]){
                cnt++;
            } else {
                cnt = 1;
            }
            if(cnt>=k) ans++;
        }
        return ans;
    }
};