// Ref: https://www.youtube.com/watch?v=U7fIQ7qAeuE
// Space complexity: O(N * K) - 486 ms, faster than 82.33% of C++ online submissions
//  Time complexity: O(N * K + F(O + N)) - 129.5 MB, less than 75.56% of C++ online submissions
class WordFilter {
public:
    struct TrieNode{        
        TrieNode* children[26] = {};
        vector<int> indexes;
        
        TrieNode() : children(), indexes() {}
    };
    
    void insert(TrieNode *trie, string word, int wordIndex){
        TrieNode *cur = trie;
        
        for(unsigned int i = 0; i < word.size(); i++){
            if(cur->children[word[i] - 'a'] == NULL)
                cur->children[word[i] - 'a'] = new TrieNode();
                    
            cur = cur->children[word[i] - 'a'];
            cur->indexes.push_back(wordIndex);
        }
    }
    
    vector<int> find(TrieNode *trie, string word){
        TrieNode *cur = trie;
        
        for(int i = 0; i < word.size(); i++){
            if(cur == NULL || cur->children[word[i] - 'a'] == NULL) return {};
            
            cur = cur->children[word[i] - 'a'];
        }
        
        return cur->indexes;
    }
    
    TrieNode *prefixTrie;
    TrieNode *suffixTrie;
    map<pair<string, string>, int> memo;
    
    // O(N * K)
    WordFilter(vector<string>& words) {
        prefixTrie = new TrieNode();
        suffixTrie = new TrieNode();
        
        for(int index = 0; index < (int)words.size(); index++){
            insert(prefixTrie, words[index], index);
            
            string reversed = words[index];
            reverse(reversed.begin(), reversed.end());
            
            insert(suffixTrie, reversed, index);
        }
    }
    
    // O(K + N), being K max(prefixSz, suffixSz)
    int f(string prefix, string suffix) {
        if (memo.count({prefix, suffix})){
            return memo[{prefix, suffix}];
        }
        
        int p, s;
        vector<int> pIndexes, sIndexes;
        
        pIndexes = find(prefixTrie, prefix);
        
        string revSuffix = suffix;
        reverse(revSuffix.begin(), revSuffix.end());
        
        sIndexes = find(suffixTrie, revSuffix);
                
        p = pIndexes.size() - 1, s = sIndexes.size() - 1;
        while(p >= 0 && s >= 0){
            if(pIndexes[p] > sIndexes[s]) p--;
            else if(sIndexes[s] > pIndexes[p]) s--;
            else return memo[{prefix, suffix}] = pIndexes[p];
        }
        
        return memo[{prefix, suffix}] = -1;
}
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
