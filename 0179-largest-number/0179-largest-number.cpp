class Solution {
private: 
    static bool comp(string a, string b){
        return a+b > b+a;
    }    
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> v;

        for(int i=0; i<nums.size(); ++i){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), comp);
        string ans = "";
        if(v[0]=="0") return "0";
        for(int i=0; i<v.size(); ++i){
            ans += v[i];
        }
        return ans;
    }
};