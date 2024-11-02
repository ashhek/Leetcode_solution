class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);

        vector<string>s;
        string word;
        while(iss >> word) {
            s.push_back(word);
        }
        string firstWord = s[0];
        string lastWord = s.back();

        if(firstWord[0] != lastWord.back()) {
            return false;
        }
        for(int i=1; i<s.size(); ++i) {
            if(s[i][0] != s[i-1].back()) {
                return false;
            }
        }
        return true;
    }
};