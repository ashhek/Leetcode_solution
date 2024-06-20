class Solution {
    int check(vector<int>&position, int d){
         int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int l = 0;
        int r = position.back() - position.front();
        int ans = r;

        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(position, mid)>=m){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};