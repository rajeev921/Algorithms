class TrieNode{
public:
    TrieNode* next[26];
    bool is_leaf{false};
    TrieNode* getChar(char ch){
        return next[ch - 'a'];
    }
    void addChar(char ch){
        next[ch - 'a'] = new TrieNode();
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode()) {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(word.empty())
            return;
        
        TrieNode* p = root;
        for(auto ch : word){
            if(!p->getChar(ch))
                p->addChar(ch);
            p = p->getChar(ch);    
        }
        p->is_leaf = true;
        return;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool search(string word, int pos, TrieNode* root) {
        if (pos == word.size()) 
            return root->is_leaf;
        if (word[pos] != '.') {
            root = root->getChar(word[pos]);
            return root ? search(word, pos + 1, root) : false;
        }
        
        for(int i{}; i < 26; ++i){
            if (root->next[i] && search(word, pos + 1, root->next[i]))
                return true;
        }
        
        return false;
    }
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */