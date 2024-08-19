class Solution {
    int findKth(vector<int>nums1, vector<int>nums2, int n, int m, int k){
        if(n > m) return findKth(nums2, nums1, m, n, k);

        int low = max(0, k-m);
        int high = min(k, n);
        int left = k;

        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN; int l2 = INT_MIN;
            int r1 = INT_MAX; int r2 = INT_MAX;

            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];

            if(mid1 > 0) l1 = nums1[mid1-1];
            if(mid2 > 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if(l1 > r2){
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int x = n+m;

        int odd = (double)findKth(nums1, nums2, n, m, (x/2)+1);
        int even = (double)findKth(nums1, nums2, n, m, (x/2));

        if(x & 1) {
            return odd;
        } else {
            return (odd+even)/2.0;
        }
        return -1;
    }
};