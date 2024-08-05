class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp;
        for(auto st : words1){
            if(mp[st]==-1) continue;
            mp[st]++;
            if(mp[st] > 1) mp[st] = -1;
        }
        for(auto st : words2){
            mp[st]--;
        }
        int count= 0;
        for(auto it : mp){
            if(it.second==0) count++;
        }
        return count;
    }
};