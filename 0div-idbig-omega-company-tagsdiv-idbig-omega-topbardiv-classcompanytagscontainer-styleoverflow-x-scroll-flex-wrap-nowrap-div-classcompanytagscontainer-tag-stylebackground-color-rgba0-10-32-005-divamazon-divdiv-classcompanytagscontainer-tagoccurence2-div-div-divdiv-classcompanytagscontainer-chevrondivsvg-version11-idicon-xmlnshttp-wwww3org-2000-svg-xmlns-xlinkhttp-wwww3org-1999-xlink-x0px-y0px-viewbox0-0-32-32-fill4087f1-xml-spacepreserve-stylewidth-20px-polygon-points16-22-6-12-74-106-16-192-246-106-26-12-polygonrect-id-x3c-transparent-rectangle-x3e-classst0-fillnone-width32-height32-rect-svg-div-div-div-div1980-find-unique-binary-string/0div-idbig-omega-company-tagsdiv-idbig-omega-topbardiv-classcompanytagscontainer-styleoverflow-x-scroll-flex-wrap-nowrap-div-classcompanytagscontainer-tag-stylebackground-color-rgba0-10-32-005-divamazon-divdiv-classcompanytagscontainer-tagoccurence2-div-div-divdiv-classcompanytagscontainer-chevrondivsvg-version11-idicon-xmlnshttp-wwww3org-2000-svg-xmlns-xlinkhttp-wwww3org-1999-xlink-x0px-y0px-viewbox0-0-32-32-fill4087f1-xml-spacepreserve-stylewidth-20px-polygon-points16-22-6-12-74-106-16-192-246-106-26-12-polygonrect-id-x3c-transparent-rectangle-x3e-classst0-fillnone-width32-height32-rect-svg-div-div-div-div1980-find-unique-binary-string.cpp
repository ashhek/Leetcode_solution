class Solution {
private: 
    void f(int i, int n, string temp, vector<string>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        f(i+1, n, temp+'1', ans);
        f(i+1, n, temp+'0', ans);   
    }    
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> sub;
        int n = nums.size();
        f(0, n, "", sub);
        int i = 0;
        //for(auto it:sub) cout << it << " ";
        sort(sub.begin(), sub.end());
        sort(nums.begin(), nums.end());
       for(auto it:nums){
           if(it != sub[i]) return sub[i];
           else i++;
       }
       return sub[n];
    }
};