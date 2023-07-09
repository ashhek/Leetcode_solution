class Solution {
public:
    string minWindow(string s, string p) {
      int minLen = INT_MAX, startPos = -1;
        int n = s.size();
        map<char,int> mp;
        int counter = p.size();
        for(auto i: p)
        mp[i]++;
        int i=0,j=0;
        while(j<n){
            char c = s[j];
            mp[c]--;
            if(mp[c]>=0) --counter;
            
            while(counter == 0){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    startPos = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) ++counter;
                ++i;
            }
            ++j;
        }
        
        if(startPos == -1){
            return "";
        } else {
            return s.substr(startPos, minLen);
        }
    }
};