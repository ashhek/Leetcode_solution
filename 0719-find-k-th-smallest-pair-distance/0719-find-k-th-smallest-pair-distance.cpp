class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int>vec;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j){
                vec.push_back(abs(nums[i]-nums[j]));
            }
        }
       nth_element(vec.begin(), vec.begin() + (k-1), vec.end());
       return vec[k-1];
    }
};