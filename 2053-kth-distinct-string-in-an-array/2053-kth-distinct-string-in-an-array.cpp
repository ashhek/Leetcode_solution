class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans = "";
        int count = 0;
        for(auto &st : arr){
            string s = st;
            int cnt = 0;
            for(auto &t : arr){
                if(s==t) cnt++;
            }
            if(cnt==1) count++;
            if(count==k) return s; 
        }
        return ans;
    }
};