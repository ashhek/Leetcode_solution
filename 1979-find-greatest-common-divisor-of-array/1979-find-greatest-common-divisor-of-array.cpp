class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int small = *min_element(nums.begin(), nums.end());

        return __gcd(largest,small);
    }
};