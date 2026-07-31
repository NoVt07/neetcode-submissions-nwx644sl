class TrieNode {
public: 
    TrieNode* children[26];
    bool is_word;

    TrieNode() {
        is_word = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    } 
};

class PrefixTree {
private: 
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix) {
            int idx = c - 'a';
            if(curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
