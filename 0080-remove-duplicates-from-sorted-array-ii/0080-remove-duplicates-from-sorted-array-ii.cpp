class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        int j = 0;

        for(auto& e:nums) {
            m[e]++;
            if(m[e] <= 2){
                nums[j] = e;
                j++;
            }
        }
        
         return j;

    }
};