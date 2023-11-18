class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
      
      unordered_map<int,int>s;
      for(auto it:nums) s[it]++;
       vector<int>ans;

     for(auto it:s){
         if(it.second==1 and s.find(it.first+1)==s.end() and s.find(it.first-1)==s.end()) ans.push_back(it.first);
     }  
     return ans;
     
    }
};