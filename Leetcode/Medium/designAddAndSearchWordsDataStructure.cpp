// Ref: https://www.youtube.com/watch?v=BTf05gs_8iU

// Space:  558.4 MB, less than 18.38% of C++ online submissions
//  Time: 1144 ms, faster than 17.36% of C++ online submissions
class WordDictionary {
public:
    struct TrieNode{
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    
    TrieNode *trie = new TrieNode();
    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode *cur = trie;
        
        for(unsigned int i = 0; i < word.size(); i++){
            if(cur->children[word[i] - 'a'] == NULL)
                cur->children[word[i] - 'a'] = new TrieNode();
                    
            cur = cur->children[word[i] - 'a'];
        }
        
        cur->isEnd = true;
    }
    
    bool dfs(int index, TrieNode* root, string &word){
        if(index == word.size()) return root->isEnd;
        
        char c = word[index];

        if(c == '.'){
            for(unsigned int i = 0; i < 26; i++){
                if(root->children[i] != NULL){
                    if(dfs(index + 1, root->children[i], word) == true) return true;
                }
            }

            return false;
        }
        else{
            if(root->children[c - 'a'] == NULL) return false;
            else return dfs(index + 1, root->children[c - 'a'], word);
        }
        
        return false;
    }
    
    bool search(string word) {
        return dfs(0, trie, word);
    }
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
