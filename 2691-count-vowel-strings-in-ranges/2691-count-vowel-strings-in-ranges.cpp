class Solution {
    bool isVowel(char &ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int>prefCount(n, 0);
        if(isVowel(words[0][0]) && isVowel(words[0].back())) {
            prefCount[0] = 1;
        }
        for(int i=1; i<n; ++i) {
            prefCount[i] = prefCount[i-1] + (isVowel(words[i][0]) && isVowel(words[i].back()) ? 1 : 0);
        }
        vector<int>ans;
        for(auto& q : queries) {
            int l = q[0];
            int r = q[1];
            if(l-1 >= 0)
            ans.push_back(prefCount[r] - prefCount[l-1]);
            else ans.push_back(prefCount[r]);
        }
        return ans;
    }
};