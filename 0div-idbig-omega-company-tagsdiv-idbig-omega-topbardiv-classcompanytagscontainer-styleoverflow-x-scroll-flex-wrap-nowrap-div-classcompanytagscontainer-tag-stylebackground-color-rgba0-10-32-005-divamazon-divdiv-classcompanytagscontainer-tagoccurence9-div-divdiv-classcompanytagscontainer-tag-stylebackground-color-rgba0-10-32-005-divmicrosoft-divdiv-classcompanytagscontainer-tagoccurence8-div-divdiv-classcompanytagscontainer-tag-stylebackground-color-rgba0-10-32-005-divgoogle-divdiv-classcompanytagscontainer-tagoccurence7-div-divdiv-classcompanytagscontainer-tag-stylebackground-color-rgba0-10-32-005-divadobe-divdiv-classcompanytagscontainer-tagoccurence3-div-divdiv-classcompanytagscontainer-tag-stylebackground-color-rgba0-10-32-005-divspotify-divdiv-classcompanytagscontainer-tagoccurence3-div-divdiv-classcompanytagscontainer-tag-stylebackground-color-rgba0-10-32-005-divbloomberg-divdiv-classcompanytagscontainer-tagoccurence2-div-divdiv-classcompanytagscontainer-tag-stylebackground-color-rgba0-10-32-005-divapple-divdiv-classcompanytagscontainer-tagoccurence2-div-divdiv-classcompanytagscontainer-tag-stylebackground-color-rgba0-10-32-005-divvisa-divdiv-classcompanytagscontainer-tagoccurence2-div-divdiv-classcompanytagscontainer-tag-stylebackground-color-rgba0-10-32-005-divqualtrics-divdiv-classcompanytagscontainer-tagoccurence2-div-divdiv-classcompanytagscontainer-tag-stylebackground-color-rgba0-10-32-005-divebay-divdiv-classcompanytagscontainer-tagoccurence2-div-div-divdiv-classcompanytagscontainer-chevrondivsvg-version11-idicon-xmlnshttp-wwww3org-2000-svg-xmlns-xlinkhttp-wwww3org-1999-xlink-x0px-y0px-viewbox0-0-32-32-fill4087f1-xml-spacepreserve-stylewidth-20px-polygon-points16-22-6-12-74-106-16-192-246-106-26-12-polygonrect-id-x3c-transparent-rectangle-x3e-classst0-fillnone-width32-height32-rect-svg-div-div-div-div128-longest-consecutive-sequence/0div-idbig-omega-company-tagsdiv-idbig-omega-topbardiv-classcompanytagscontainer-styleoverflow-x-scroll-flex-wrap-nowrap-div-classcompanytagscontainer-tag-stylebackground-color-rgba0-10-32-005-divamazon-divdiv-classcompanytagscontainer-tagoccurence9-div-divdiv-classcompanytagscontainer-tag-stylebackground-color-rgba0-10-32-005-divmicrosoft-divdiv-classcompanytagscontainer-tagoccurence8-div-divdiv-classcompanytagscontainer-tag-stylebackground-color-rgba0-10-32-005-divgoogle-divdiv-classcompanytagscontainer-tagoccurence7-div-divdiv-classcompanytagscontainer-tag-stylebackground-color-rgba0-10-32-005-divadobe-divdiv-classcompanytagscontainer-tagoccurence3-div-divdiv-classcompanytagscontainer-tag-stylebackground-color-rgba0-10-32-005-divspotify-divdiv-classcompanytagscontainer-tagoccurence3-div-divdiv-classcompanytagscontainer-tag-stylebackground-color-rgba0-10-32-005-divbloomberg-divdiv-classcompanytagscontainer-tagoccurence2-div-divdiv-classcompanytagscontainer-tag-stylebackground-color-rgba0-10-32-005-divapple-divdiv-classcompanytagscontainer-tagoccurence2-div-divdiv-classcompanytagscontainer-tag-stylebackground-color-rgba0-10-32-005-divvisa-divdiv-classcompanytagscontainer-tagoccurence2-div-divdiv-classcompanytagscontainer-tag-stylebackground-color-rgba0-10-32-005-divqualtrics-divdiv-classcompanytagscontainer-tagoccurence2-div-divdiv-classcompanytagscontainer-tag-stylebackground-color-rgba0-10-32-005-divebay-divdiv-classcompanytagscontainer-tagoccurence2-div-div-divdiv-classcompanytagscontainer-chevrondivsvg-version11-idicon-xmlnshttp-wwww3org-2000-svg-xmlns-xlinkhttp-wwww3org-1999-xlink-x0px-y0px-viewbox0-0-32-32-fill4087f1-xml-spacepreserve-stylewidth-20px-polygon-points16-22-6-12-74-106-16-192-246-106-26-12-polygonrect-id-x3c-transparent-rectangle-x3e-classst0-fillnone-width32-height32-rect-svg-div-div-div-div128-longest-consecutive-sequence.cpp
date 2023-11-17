class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());

        int mxlen = 0;

        for(auto num : numSet){
            if(numSet.find(num-1)==numSet.end()){
                int start = num;
                int curr = 1;

                while(numSet.find(start+1) != numSet.end()){
                    start++;
                    curr++;
                }

                mxlen = max(mxlen, curr);
            }
        }
        return mxlen;
    }
};