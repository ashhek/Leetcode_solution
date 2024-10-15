class Trie {
public:
    struct TreeNode {
        TreeNode* children[26];
        bool isEndOfWord;
    };
    TreeNode* getNode() {
        TreeNode* newNode = new TreeNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; ++i) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    TreeNode* root;
    Trie() { root = getNode(); }

    void insert(string word) {
        TreeNode* ptr = root;

        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!ptr->children[idx]) {
                ptr->children[idx] = getNode();
            }
            ptr = ptr->children[idx];
        }
        ptr->isEndOfWord = true;
    }

    bool search(string word) {
        TreeNode* ptr = root;

        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!ptr->children[idx]) {
                return false;
            }
            ptr = ptr->children[idx];
        }
        return (ptr && ptr->isEndOfWord);
    }

    bool startsWith(string prefix) {
        TreeNode* ptr = root;
        int i;
        for (i = 0; i < prefix.size(); ++i) {
            int idx = prefix[i] - 'a';

            if (!ptr->children[idx]) {
                return false;
            }
            ptr = ptr->children[idx];
        }
        return (i == prefix.size());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */