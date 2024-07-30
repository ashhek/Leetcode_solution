class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            vector<int>temp;
            int count = n;
            int j = i;
            while(count--){
                temp.push_back(nums[(j+n)%n]);
                j++;
            }
            if(is_sorted(temp.begin(), temp.end())) return true;
        }
        return false;
    }
};