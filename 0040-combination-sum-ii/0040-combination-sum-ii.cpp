class Solution {
    void uniqCandi(int i, vector<int>& candidates, int target,
                   set<vector<int>>& st, vector<int> temp) {
        if (target == 0) {
            st.insert(temp);
            return;
        }
        if (i == candidates.size()) {
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            uniqCandi(i + 1, candidates, target - candidates[i], st, temp);
            temp.pop_back();
        }
        while(i+1 < candidates.size()) {
            if(candidates[i] == candidates[i+1]) 
            i++;
            else break;
        }
        return uniqCandi(i + 1, candidates, target, st, temp);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        uniqCandi(0, candidates, target, st, temp);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};