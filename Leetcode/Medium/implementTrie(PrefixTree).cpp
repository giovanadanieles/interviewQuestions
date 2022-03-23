// Space: 43.2 MB, less than 88.19% of C++ online submissions
//  Time: 80 ms, faster than 64.82% of C++ online submissions
class Trie {
public:
    struct TrieNode{
        bool isEnd;
        unordered_map<char, TrieNode*> children;
        
        TrieNode() : isEnd(false), children() {}
        TrieNode(int v, bool e) : isEnd(e), children() {}
    };
    
    TrieNode *trie = new TrieNode();
    Trie() {}
    
    // Time: O(N), being N word size
    void insert(string word) {
        TrieNode *cur = trie;
        
        for(int i = 0; i < word.size(); i++){
            if(cur->children.find(word[i]) == cur->children.end()){
                if(i < word.size() - 1) cur->children[word[i]] = new TrieNode(word[i], false);
                else cur->children[word[i]] = new TrieNode(word[i], true);
            }
      
            cur = cur->children[word[i]];
        }
        
        cur->isEnd = true;
    }
    
    // Time: O(N), being N word size
    bool search(string word) {
        TrieNode *cur = trie;
        
        for(int i = 0; i < word.size(); i++){
            if(cur == NULL || cur->children.find(word[i]) == cur->children.end()) return false;
            
            cur = cur->children[word[i]];
        }
        
        return cur->isEnd;
    }
    
    // Time: O(N), being N prefix size
    bool startsWith(string prefix) {
        TrieNode *cur = trie;
        
        for(int i = 0; i < prefix.size(); i++){
            if(cur == NULL || cur->children.find(prefix[i]) == cur->children.end()) return false;
            
            cur = cur->children[prefix[i]];
        }
        
        return true;
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
