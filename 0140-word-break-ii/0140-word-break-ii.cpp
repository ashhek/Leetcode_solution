class Solution {
public:
    // struct TrieNode() {
    //     TreeNode* children[26];
    //     bool isEndOfWord;
    // };
    // TreeNode* getNode() {
    //     TreeNode* newNode = new TreeNode();
    //     newNode->isEndOfWord = false;

    //     for(int i=0; i<26; ++i) {
    //         newNode->children[i] = NULL;
    //     }
    //     return newNode;
    // }
    // void insert(string word, TreeNode* root) {
    //     TreeNode* ptr = root;

    //     for(int i=0; i<word.size(); ++i) {
    //         int ind = word[i];
    //         if(!ptr->children[ind]) {
    //             ptr->children[ind] = getNode();
    //         }
    //         ptr = ptr->children[ind];
    //     }
    //     ptr->isEndOfWord = true;
    // }
    vector<string>res;
    void backTrack(int i, string& s, unordered_set<string>& st, string temp) {
        if(i==s.size()) {
            string ref = temp.substr(0, temp.size()-1);
            res.push_back(ref);
            return;
        }

        for(int j=i; j<s.size(); ++j) {
            string t = s.substr(i, j-i+1);

            if(st.find(t) != st.end()) {
                backTrack(j+1, s, st, temp+t+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());

        string temp;
        backTrack(0, s, st, temp);
        return res;
    }
};