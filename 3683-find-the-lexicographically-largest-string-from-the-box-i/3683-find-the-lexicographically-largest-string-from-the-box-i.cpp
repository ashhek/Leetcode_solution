class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string s = word;
        sort(s.begin(), s.end());
        int lastChar = s[n - 1];

        if(numFriends == 1) return word;

        numFriends--;
        vector<string>temp;
        
        for (int i = 0; i < n; ++i) {
            if (word[i] == lastChar) {
                int j = i;
                int k = n - numFriends;
                string ans = "";
                while (j < n && k > 0) {
                    ans += word[j];
                    j++;
                    k--;
                }
                temp.push_back(ans);
            }
        }
        sort(temp.begin(), temp.end());
        string res = temp.back();
        return res;
    }
};