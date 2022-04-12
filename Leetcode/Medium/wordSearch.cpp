// Ref: https://www.youtube.com/watch?v=pfiQ_PS1g8E

// Space complexity: O(N * M) - 8.1 MB, less than 36.08% of C++ online submissions
//  Time complexity: O(N * M * 4 ^ word_length) - 815 ms, faster than 25.63% of C++ online submissions
class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string word, bool &exists){
        if(word.size() == 0){
            exists = true;
            return;
        }
        if(x >= board.size() || x < 0 || y >= board[0].size() || y < 0) return;
        if(visited[x][y] == true) return;
        if(exists == true) return;
        
        if(board[x][y] == word[0]){
            word = word.substr(1);
            visited[x][y] = true;
            
            dfs(board, visited, x + 1, y, word, exists);
            dfs(board, visited, x - 1, y, word, exists);
            dfs(board, visited, x, y + 1, word, exists);
            dfs(board, visited, x, y - 1, word, exists);
            
            visited[x][y] = false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        
        for(unsigned int row = 0; row < board.size(); row++){
            for(unsigned int col = 0; col < board[row].size(); col++){
                if(board[row][col] == word[0]){
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    dfs(board, visited, row, col, word, ans);
                }
                if(ans == true) return true;
            }
        }
        
        return false;
    }
};
