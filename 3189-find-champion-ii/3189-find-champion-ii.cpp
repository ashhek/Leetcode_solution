class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
	    int ans = -1, cnt = 0;
        vector<int> indegree(n, 0);
         for(auto it: edges){
           indegree[it[1]]++;
         }
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0) {
            cnt++; 
            ans = i; 
            }
    }
    if(cnt>1) return -1;
    return ans;
    }
};