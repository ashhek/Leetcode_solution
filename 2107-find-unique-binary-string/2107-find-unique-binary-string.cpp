class Solution {
    string res = "";
    void help(vector<string>&nums, set<string>&st, string temp) {
        if(temp.size() ==nums.size() && st.find(temp) == st.end()) {
            res = temp;
            return;
        }
        if(temp.size() > nums.size()) return;

        temp.push_back('1');
        help(nums, st, temp);
        temp.pop_back();
        temp.push_back('0');
        help(nums, st, temp);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st(nums.begin(), nums.end());
        string temp;
        help(nums, st, temp);
        return res;
    }
};