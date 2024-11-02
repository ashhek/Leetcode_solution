class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);

        vector<string>s;
        string word;
        while(iss >> word) {
            s.push_back(word);
        }
        int n = s.size();

        if(s[0].front() != s[n-1].back()) {
            return false;
        }
        for(int i=1; i<s.size(); ++i) {
            if(s[i].front() != s[i-1].back()) {
                return false;
            }
        }
        return true;
    }
};