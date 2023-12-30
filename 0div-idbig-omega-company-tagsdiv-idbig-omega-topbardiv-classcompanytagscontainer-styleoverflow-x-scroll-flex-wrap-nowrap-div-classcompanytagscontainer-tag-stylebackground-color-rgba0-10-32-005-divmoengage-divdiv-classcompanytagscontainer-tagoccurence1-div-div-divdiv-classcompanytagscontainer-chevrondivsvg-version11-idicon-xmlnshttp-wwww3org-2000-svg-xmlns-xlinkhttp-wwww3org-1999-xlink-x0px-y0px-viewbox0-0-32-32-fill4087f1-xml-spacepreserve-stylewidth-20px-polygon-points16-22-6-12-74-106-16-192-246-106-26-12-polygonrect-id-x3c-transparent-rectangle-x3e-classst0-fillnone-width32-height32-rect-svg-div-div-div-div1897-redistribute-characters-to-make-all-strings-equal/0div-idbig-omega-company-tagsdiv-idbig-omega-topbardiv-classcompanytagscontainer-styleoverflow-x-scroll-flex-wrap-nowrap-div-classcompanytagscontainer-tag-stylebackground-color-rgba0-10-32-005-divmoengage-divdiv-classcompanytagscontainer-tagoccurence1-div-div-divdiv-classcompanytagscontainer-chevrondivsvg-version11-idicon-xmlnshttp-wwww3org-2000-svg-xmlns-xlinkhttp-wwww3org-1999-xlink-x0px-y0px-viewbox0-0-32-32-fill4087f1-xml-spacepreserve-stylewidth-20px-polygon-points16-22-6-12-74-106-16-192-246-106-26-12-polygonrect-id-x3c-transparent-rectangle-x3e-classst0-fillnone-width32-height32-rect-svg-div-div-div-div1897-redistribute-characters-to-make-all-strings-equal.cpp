class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1) return true;
        unordered_map<char,int>m;
        for(auto it:words) {
            for(auto ch:it){
                m[ch]++;
            }
        }

        for(auto it:m){
           if(it.second%words.size() != 0){
               return false;
           }
        }
        return true;
      
    }
};