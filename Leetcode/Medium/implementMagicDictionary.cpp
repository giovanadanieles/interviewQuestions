// Space: 95.4 MB, less than 50.92% of C++ online submissions
//  Time: 104 ms, faster than 76.38% of C++ online submissions
class MagicDictionary {
public:
    struct TrieNode{
        TrieNode *children[26] = {};
        bool word = false;
    };
    
    TrieNode *trie = new TrieNode();
    MagicDictionary() {}
    
    // Space complexity: O(26 * szLargestWord)
    //  Time complexity: O(numWords * sizeWords)
    void buildDict(vector<string> dictionary) {
        TrieNode *cur;
        
        for(unsigned int i = 0; i < dictionary.size(); i++){
            cur = trie;
            
            for(unsigned int j = 0; j < dictionary[i].size(); j++){
                if(cur->children[dictionary[i][j] - 'a'] == NULL)
                    cur->children[dictionary[i][j] - 'a'] = new TrieNode();
                
                cur = cur->children[dictionary[i][j] - 'a'];
            }
            
            cur->word = true;
        }
    }
    
    //  Time complexity: O(qtd_nodes_trie)
    bool dfs(int index, int changed, TrieNode *root, string &word){
        if(index == word.size()){
            if(changed == 1) return root->word;
            else return false;
        }
        else if(index >= word.size()) return false;
        if(root == NULL) return false;
        
        for(unsigned int i = 0; i < 26; i++){                
            if(root->children[i] != NULL){
                if(i == (word[index] - 'a')){
                    if(dfs(index + 1, changed, root->children[i], word) == true) return true;
                }
                else if(changed == 0){
                    if(dfs(index + 1, changed + 1, root->children[i], word) == true) return true;
                }
            }  
        }
        
        return false;
    }
    
    bool search(string searchWord) {
        return dfs(0, 0, trie, searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
