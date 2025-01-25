class Solution {
    int findKth(vector<int>nums1, vector<int>nums2, int n, int m, int k) {
        if(n > m) {
            return findKth(nums2, nums1, m, n, k);
        }
        int low = max(0, k-m);
        int high = min(k, n);

        while(low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;

            int l1 = mid1 > 0 ? nums1[mid1-1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2-1] : INT_MIN;
            int r1 = mid1 < n ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < m ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if(l1 > r2) {
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

        int x = n + m;

        double first = (double)findKth(nums1, nums2, n, m, x/2+1);
        double second = (double)findKth(nums1, nums2, n, m, x/2);
        if(x & 1) {
            return first;
        }
        return (first+second)/2.0;
    }
};
