// Space complexity: O(N^2) - 10 MB, less than 78.00% of C++ online submissions
//  Time complexity: O(N^2) - 15 ms, faster than 67.87% of C++ online submissions
class Solution {
public:
    void sink(vector<vector<char>> &board, int x, int y){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        if(board[x][y] == 'X' || board[x][y] == 'S') return;
        
        board[x][y] = 'S';
        
        sink(board, x + 1, y);
        sink(board, x - 1, y);
        sink(board, x, y + 1);
        sink(board, x, y - 1);
    }
    
    void solve(vector<vector<char>>& board) {     
        for(int topRow = 0; topRow < (int)board[0].size(); topRow++) sink(board, 0, topRow);
        for(int rightCol = 0; rightCol < (int)board.size(); rightCol++) sink(board, rightCol, board[0].size() - 1);
        for(int bottomRow = (int)board[0].size() - 1; bottomRow >= 0; bottomRow--) sink(board, board.size() - 1, bottomRow);
        for(int leftCol = (int)board.size() - 1; leftCol >= 0; leftCol--) sink(board, leftCol, 0);
        
        for(unsigned int row = 0; row < board.size(); row++){
            for(unsigned int col = 0; col < board[0].size(); col++){
                if(board[row][col] == 'O') board[row][col] = 'X';
                if(board[row][col] == 'S') board[row][col] = 'O';
            }
        }
    }
};
