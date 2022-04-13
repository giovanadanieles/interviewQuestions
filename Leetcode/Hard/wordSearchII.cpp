// TIME LIMIT EXCEEDED :(
// class Solution {
// public:
//     void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string word, bool &exists){
//         if(word.size() == 0){
//             exists = true;
//             return;
//         }
//         if(x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return;
//         if(visited[x][y] == true) return;
//         if(exists == true) return;
        
//         if(board[x][y] == word[0]){
//             word = word.substr(1);
//             visited[x][y] = true;
            
//             dfs(board, visited, x + 1, y, word, exists);
//             dfs(board, visited, x - 1, y, word, exists);
//             dfs(board, visited, x, y + 1, word, exists);
//             dfs(board, visited, x, y - 1, word, exists);
            
//             visited[x][y] = false;
//         }
//     }
    
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         bool ans;
//         vector<string> found;
        
//         for(string word : words){
//             ans = false;
            
//             for(unsigned int row = 0; row < board.size(); row++){
//                 for(unsigned int col = 0; col < board[row].size(); col++){
                    
//                     if(board[row][col] == word[0]){
//                         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
//                         dfs(board, visited, row, col, word, ans);
//                     }
                    
//                     if(ans == true){
//                         found.push_back(word);
//                         break;
//                     }
//                 }
//                 if(ans == true) break;
//             }
//         }
        
//         return found;
//     }
// };



// Ref: https://www.youtube.com/watch?v=asbcE9mZz_U

// Space complexity: O(M * N) - 14.1 MB, less than 14.75% of C++ online submissions
//  Time complexity: O(M * N * 3 ^ T), being T the size of the largest word - 1659 ms, faster than 10.35% of C++ online submissions
class Solution {
public:  
    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        int isWord;
        
        TrieNode() : isWord(false) {}
    };
    
    void addWordToTrie(TrieNode *root, string word){
        for(char letter: word){
            if(root->children.find(letter) == root->children.end()) root->children[letter] = new TrieNode();
            
            root = root->children[letter];
        }
        
        root->isWord = true;
    }
    
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, TrieNode *root, string word, int x, int y,
             vector<string> &found){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(visited[x][y] == true) return;
        if(root->children.find(board[x][y]) == root->children.end()) return;
        
        visited[x][y] = true;
        root = root->children[board[x][y]];
        word += board[x][y];
        
        if(root->isWord == true){
            found.push_back(word);
            root->isWord = false;
        }
        
        dfs(board, visited, root, word, x + 1, y, found);
        dfs(board, visited, root, word, x - 1, y, found);
        dfs(board, visited, root, word, x, y + 1, found);
        dfs(board, visited, root, word, x, y - 1, found);
        
        visited[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *trie = new TrieNode();
        vector<string> found;
        
        for(string word : words) addWordToTrie(trie, word);
        
        for(unsigned int row = 0; row < board.size(); row++){
            for(unsigned int col = 0; col < board[row].size(); col++){
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                
                dfs(board, visited, trie, "", row, col, found);
            }
        }
                
        return found;
    }
};
