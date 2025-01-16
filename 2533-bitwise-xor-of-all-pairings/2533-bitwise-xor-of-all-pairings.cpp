class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        int xr1 = nums1[0];
        int xr2 = nums2[0];

        for(int i=1; i<nums1.size(); ++i) {
            xr1 ^= nums1[i];
        }
        for(int i=1; i<nums2.size(); ++i) {
            xr2 ^= nums2[i];
        }
        if(n%2 == 1 && m%2 == 0) return xr2;
        if(n%2 == 0 && m%2 == 1) return xr1;
        if(n%2 == 0 && m%2 == 0) return 0;
        return xr1^xr2;
    }
};