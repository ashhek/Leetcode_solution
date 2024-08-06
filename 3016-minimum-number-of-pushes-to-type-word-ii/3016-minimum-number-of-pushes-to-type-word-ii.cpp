class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char,int>mp;
        
        for(int i=0; i<n; ++i){
            mp[word[i]]++;
        }
        vector<int>v;
        for(auto it:mp) v.push_back(it.second);
        
        sort(v.begin(), v.end(), greater<int>());
        int i = 0;
        int ans = 0;
        while(i<v.size() and i<8){
            ans += v[i];
            i++;
        }
         while(i<v.size() and i>=8 and i<16){
            ans += 2*v[i];
            i++;
        }
         while(i<v.size() and i>=16 and i<24){
            ans += 3*v[i];
            i++;
        }
          while(i<v.size() and i>=24 ){
            ans += 4*v[i];
            i++;
        }
       
        return ans;
    }
};