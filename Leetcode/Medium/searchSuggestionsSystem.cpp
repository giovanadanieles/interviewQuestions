// Space complexity: O(M), being M number of characters in products - 660.5 MB, less than 5.29% of C++ online submissions
//  Time complexity: O(26N), being N number of nodes in Trie - 1828 ms, faster than 5.04% of C++ online submissions
class Solution {
public:
    struct TrieNode{
        TrieNode *children[26];
        bool isWord;
        
        TrieNode(bool w) : children(), isWord(w) {}
    };
    
    // O(M), being M the total num of characters in products
    void insert(string word){
        TrieNode *cur = trie;
        
        for(auto c : word){
            if(cur->children[c - 'a'] == NULL){
                cur->children[c - 'a'] = new TrieNode(false);
            }
            
            cur = cur->children[c - 'a'];
        }
        
        cur->isWord = true;
    }
    
    // O(M)
    void findSuggestions(TrieNode *cur, string curWord, vector<string> &result, int &numOfSugg){
        if(numOfSugg == 0 || cur == NULL) return;
        
        if(cur->isWord == true){
            numOfSugg--;
            result.push_back(curWord);
        }
        
        for(char c = 'a'; c <= 'z' && numOfSugg > 0; c++){
            if(cur->children[c - 'a'] != NULL){
                curWord += c;
                findSuggestions(cur->children[c - 'a'], curWord, result, numOfSugg);
                curWord.pop_back();
            }
        }
    }
    
    // O(len(word))
    vector<string> find(string word){
        int numOfSugg = 3;
        TrieNode *cur = trie;
        string curString = "";
        vector<string> result;
        
        for(auto c : word){
            if(cur == NULL || cur->children[c - 'a'] == NULL) return result;
            
            curString += c;
            cur = cur->children[c - 'a'];
        }
        
        findSuggestions(cur, curString, result, numOfSugg);
        
        return result;
    }
    
    TrieNode *trie;
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string search = "";
        vector<vector<string>> ans;
        
        trie = new TrieNode(false);
        
        for(auto product : products){
            insert(product);
        }
        
        for(auto c : searchWord){
            vector<string> results;
            
            search += c;
            results = find(search);
            
            ans.push_back(results);
        }
        
        return ans;
    }
};
