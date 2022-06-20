// Space complexity: O(totalWSize) - 73.9 MB, less than 30.88% of C++ online submissions
//  Time complexity: O(WlogW), being W num of words - 169 ms, faster than 27.94% of C++ online submissions
// class Solution {
// public:
//     struct TrieNode{
//         TrieNode* children[26];
        
//         TrieNode() : children() {}
//     };
    
//     void trieInsert(string word){
//         TrieNode *cur = trie;
        
//         for(int index = (int)word.size() - 1; index >= 0; index--){
//             if(cur->children[word[index] - 'a'] == NULL){
//                 cur->children[word[index] - 'a'] = new TrieNode();
//             }
            
//             cur = cur->children[word[index] - 'a'];
//         }
//     }
    
//     bool trieFind(string word){
//         TrieNode *cur = trie;
        
//         for(int index = (int)word.size() - 1; index >= 0; index--){
//             if(cur == NULL || cur->children[word[index] - 'a'] == NULL){
//                 return false;
//             }
            
//             cur = cur->children[word[index] - 'a'];
//         }
        
//         return true;
//     }
    
//     static bool customCmp(string a, string b){
//         reverse(a.begin(), a.end());
//         reverse(b.begin(), b.end());
        
//         return a > b;
//     }
    
//     TrieNode *trie;
    
//     int minimumLengthEncoding(vector<string>& words) {
//         int ans = 0;
        
//         trie = new TrieNode();
        
//         sort(words.begin(), words.end(), customCmp);
        
//         for(auto word : words){
//             if(trieFind(word) == false){
//                 trieInsert(word);
//                 ans += word.size() + 1;
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(sum(W_i)), being W total length of words - 77.3 MB, less than 16.67% of C++ online submissions
//  Time complexity: O(sum(W_i)) - 98 ms, faster than 60.29% of C++ online submissions
class Solution {
public:
    struct TrieNode{
        bool hasChildren;
        TrieNode* children[26];
        
        TrieNode() : hasChildren(false), children() {}
    };
    
    TrieNode* trieInsert(string word){
        TrieNode *cur = trie;
        
        for(int index = (int)word.size() - 1; index >= 0; index--){
            if(cur->children[word[index] - 'a'] == NULL){
                cur->children[word[index] - 'a'] = new TrieNode();
                cur->hasChildren = true;
            }
            
            cur = cur->children[word[index] - 'a'];
        }

        return cur;
    }
    
    unordered_map<TrieNode*, int> leafNodes;
    TrieNode *trie;
    
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        TrieNode *aux;
        
        trie = new TrieNode();
                
        for(unsigned int index = 0; index < words.size(); index++){
            aux = trieInsert(words[index]);
            
            leafNodes[aux] = index;
        }
        
        for(auto it = leafNodes.begin(); it != leafNodes.end(); it++){
            if(it->first->hasChildren == false){
                ans += words[it->second].size() + 1;
            }
        }
        
        return ans;
    }
};
