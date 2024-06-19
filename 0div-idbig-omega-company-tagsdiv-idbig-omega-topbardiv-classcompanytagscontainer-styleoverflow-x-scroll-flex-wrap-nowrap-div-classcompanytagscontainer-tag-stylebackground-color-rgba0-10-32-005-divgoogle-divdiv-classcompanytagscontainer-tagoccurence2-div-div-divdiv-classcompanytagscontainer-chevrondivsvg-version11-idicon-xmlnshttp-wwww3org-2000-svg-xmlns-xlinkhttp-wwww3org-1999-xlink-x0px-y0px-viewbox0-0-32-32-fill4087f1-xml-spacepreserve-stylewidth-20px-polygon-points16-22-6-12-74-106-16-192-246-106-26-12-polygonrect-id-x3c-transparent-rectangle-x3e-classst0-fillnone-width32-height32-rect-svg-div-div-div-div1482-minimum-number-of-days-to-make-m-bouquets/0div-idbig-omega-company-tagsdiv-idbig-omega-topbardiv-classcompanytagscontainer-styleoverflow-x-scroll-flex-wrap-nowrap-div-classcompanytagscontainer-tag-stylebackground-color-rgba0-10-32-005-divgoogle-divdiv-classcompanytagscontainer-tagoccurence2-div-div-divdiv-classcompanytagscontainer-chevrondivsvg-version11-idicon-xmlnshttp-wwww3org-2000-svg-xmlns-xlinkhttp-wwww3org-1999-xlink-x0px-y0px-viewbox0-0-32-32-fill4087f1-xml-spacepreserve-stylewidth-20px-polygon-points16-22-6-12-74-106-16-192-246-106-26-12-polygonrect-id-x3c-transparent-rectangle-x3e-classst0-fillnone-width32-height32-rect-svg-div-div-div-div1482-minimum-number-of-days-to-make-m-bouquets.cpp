class Solution {
    int isBloom(vector<int>& bloomDay, int mid, int k){
        int cnt = 0;
        int bloom = 0;

        for(int i=0; i<bloomDay.size(); ++i){
            if(bloomDay[i] <= mid) cnt++;
            else cnt = 0;

            if(cnt==k) bloom++, cnt = 0;
        }
        return bloom;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int minDay = -1;
        int l = 0;
        int r = 1e9;

        while(l<=r){
            int mid = r - (r - l)/2;
            if(isBloom(bloomDay, mid, k) >= m){
                minDay = mid;
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return minDay;  
    }
};