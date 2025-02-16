class Solution {
    bool backTrack(int idx, vector<int>&res, vector<int>&seen, int n) {
        while(idx < res.size() && res[idx]!=0) idx++;
        if(idx == res.size()) {
            return true;
        } 

        for(int i=n; i>=1; --i) {
            if(seen[i]) continue;
            if(i == 1) {
                seen[i] = 1;
                res[idx] = i;
                if(backTrack(idx+1, res, seen, n)) return true;
                seen[i] = 0;
                res[idx] = 0;
            } else if(idx + i < res.size() && !res[idx+i]){
                seen[i] = 1;
                res[idx] = i;
                res[i+idx] = i;
                if(backTrack(idx+1, res, seen, n)) return true;
                seen[i] = 0;
                res[idx] = 0;
                res[i+idx] = 0;
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>seen(n+1, 0);
        vector<int>res(2*n-1, 0);

        backTrack(0, res, seen, n);
        return res;
    }
};