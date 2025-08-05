class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; ++i){
            bool placed = false;
            for(int j=0; j<n; ++j) {
                if(!vis[j] && baskets[j] >= fruits[i]){
                    vis[j] = 1;
                    placed = true;
                    break;
                }
            }
            if(placed == false) cnt++;
        }
        return cnt;
    }
};