class Solution {
    bool isOKtoCut(vector<vector<int>>&nums) {
        int n = nums.size();
        if(n <= 1) return false;
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        res.push_back(nums[0]);

        for(int i=1; i<n; ++i) {
            if(nums[i][0] >= res.back()[1]) {
                res.push_back(nums[i]);
            } else {
                res.back()[1] = max(res.back()[1], nums[i][1]);
            }
        }
        //return res.size() >= 2;
        for(auto it : res) {
            cout << it[0] << " " << it[1] << endl;
        }
        return res.size() >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>horz;
        vector<vector<int>>vert;
        for(auto sides : rectangles) {
            horz.push_back({sides[0], sides[2]});
            vert.push_back({sides[1], sides[3]});
        }
        return  isOKtoCut(vert) || isOKtoCut(horz);
    }
};