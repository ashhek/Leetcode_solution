class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>ans;

        for(auto& e:nums1) m[e]++;

        for(auto& e:nums2){
            if(m[e]>0){
                ans.push_back(e);
                m[e]--;
            }
        }
        return ans;
    }
};