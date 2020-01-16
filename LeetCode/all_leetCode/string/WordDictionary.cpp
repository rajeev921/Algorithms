class WordDictionary {
public:
    struct Node {
        Node* children[26] = {};
        bool isWord = false;
        Node() {}
    };
    Node *root = nullptr;
    WordDictionary() {}
    void addWord(string word) { add(word, 0, root); }
    bool search(string word) { return srch(word, 0, root); }
private:
    void add(string& word, int k, Node* &node) {
        if (!node) node = new Node();
        if (k == word.size()) node->isWord = true;
        else add(word, k+1, node->children[word[k]-'a']);
    }
    bool srch(string& word, int k, Node* node) {
        if (!node) return false;
        if (k == word.size()) return node->isWord;
        if (word[k] != '.') return srch(word, k+1, node->children[word[k]-'a']);
        for (int c = 0; c < 26; c++)
            if (srch(word, k+1, node->children[c]))
                return true;
        return false;
    }
};

============================================

class TrieNode {
public:
    TrieNode *next[26]{};
    bool is_leaf = false;
    TrieNode *get(char c) { return next[c - 'a']; }
    void add(char c) { next[c - 'a'] = new TrieNode; }
};

class WordDictionary {
public:
    WordDictionary() : root(new TrieNode) {}
    void addWord(const string &word) {
        auto p = root;
        for (auto c : word) {
            if (!p->get(c)) p->add(c);
            p = p->get(c);
        }
        p->is_leaf = true;
    }
    bool search(const string &word) {  return search(word, 0, root); }
private:
    bool search(const string &word, int pos, TrieNode *root) {
        if (pos == word.size()) return root->is_leaf;
        if (word[pos] != '.') {
            root = root->get(word[pos]);
            return root ? search(word, pos + 1, root) : false;
        }
        for (auto i = 0; i < 26; ++i)
            if (root->next[i] && search(word, pos + 1, root->next[i]))
                return true;
        return false;
    }
    TrieNode *root;
};
============================================

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary(): root(new TrieNode()) {}
    
    ~WordDictionary() {delete root;}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWord(word,0,root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word,0,root);
    }
private:
    struct TrieNode {
        TrieNode():child(vector<TrieNode*>(26,NULL)), isLeaf(false) {}
        ~TrieNode() {for(TrieNode* node:child) delete node;}
        vector<TrieNode*> child;
        bool isLeaf;
    };
    
    TrieNode* root;
    
    void addWord(const string& word, size_t i, TrieNode* cur) {
        if(i==word.length()) return;
        size_t j = word[i] - 'a';
        if(!cur->child[j]) cur->child[j] = new TrieNode();
        if(i==word.length()-1) cur->child[j]->isLeaf=true;
        addWord(word,i+1,cur->child[j]);
    }
    
    bool search(const string& word, size_t i, TrieNode* cur) const {
        if(i==word.length()) return false;
        
        if(word[i]!='.') {
            size_t j = word[i] - 'a';
            if(!cur->child[j]) return false;
            if(i==word.length()-1 && cur->child[j]->isLeaf) return true;
            return search(word,i+1,cur->child[j]);
        }
        else {
            for(TrieNode* node:cur->child) {
                if(node) {
                    if(i==word.length()-1 && node->isLeaf) return true;
                    if(search(word,i+1,node)) return true;
                }
            }
            return false;
        }
    }
    
};