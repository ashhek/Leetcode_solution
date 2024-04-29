class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int final_xor = 0;
        for (int i : nums) {
            final_xor ^= i;
        }

        return __builtin_popcount(final_xor ^ k);
    }
};