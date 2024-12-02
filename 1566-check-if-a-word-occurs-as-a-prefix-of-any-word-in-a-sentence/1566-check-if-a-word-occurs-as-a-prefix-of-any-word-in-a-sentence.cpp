class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        vector<string> s;
        while(iss >> word) {
            s.push_back(word);
        }
        int ind = 0;
        for(string& t : s) {
            ind++;
            string word = t;
            int i = 0; int j = 0;
            while(i < t.size()) {
                if(t[i] == searchWord[j]) {
                    i++;
                    j++;
                } else {
                    break;
                }
                if(j == searchWord.size()) {
                    return ind;
                }
            }
        }
        return -1;
    }
};