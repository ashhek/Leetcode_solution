class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums2.begin(), nums2.end());
        
        unordered_set<int>s(nums1.begin(), nums1.end());
        int res = -1;
        
        for(auto it:nums2){
            if(s.count(it)>0) {
                res = it;
                break;
            }
        }
        int mn1 = *min_element(nums1.begin(), nums1.end());
        int mn2 = *min_element(nums2.begin(), nums2.end());
        
        string ans = "";
        ans += to_string(min(mn1,mn2));
        ans += to_string(max(mn1,mn2));
        
        
        int a = stoi(ans);
        
        if(res!= -1 and res<a) return res;
        return a;
    }
};