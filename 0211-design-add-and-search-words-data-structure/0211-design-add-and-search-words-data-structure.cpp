class WordDictionary {
public:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];

        TrieNode() {
            isEndOfWord = false;
            for(int i=0; i<26; ++i) {
                children[i] = nullptr;
            }
        }
    };
   
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* ptr = root;
        for(char& ch : word) {
            int idx = ch - 'a';
                if(ptr->children[idx] == nullptr) {
                    ptr->children[idx] = new TrieNode();
                }
            ptr = ptr->children[idx];
        }
        ptr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }

    bool dfs(int idx, string& word, TrieNode* root) {
        TrieNode* ptr = root;

        for(int i = idx; i < word.size(); ++i) {
            if(word[i] == '.') {
                for(auto child : ptr->children) {
                    if(child != nullptr && dfs(i+1, word, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if(ptr->children[word[i] - 'a'] == nullptr) {
                    return false;
                }
                ptr = ptr->children[word[i] - 'a'];
            }
        }
        return (ptr && ptr->isEndOfWord);
    }
};
