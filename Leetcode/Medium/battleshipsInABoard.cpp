//   Solution #1:
// class Solution {
// public:
//     int countBattleships(vector<vector<char>>& board) {
//         int numBattleships = 0;
        
//         for(unsigned int i = 0; i < board.size(); i++){
//             for(unsigned int j = 0; j < board[i].size(); j++){
//                 if(board[i][j] == 'X'){
//                     numBattleships++;
                    
//                     sink(i, j, board);
//                 }
//             }
//         }
        
//         return numBattleships;
//     }
    
//     void sink(unsigned int x, unsigned int y, vector<vector<char>>& board){
//         if(x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] == '.') 
//             return;
        
//         board[x][y] = '.';
        
//         sink(x + 1, y, board);
//         sink(x, y + 1, board);
//     }
// };



//   Solution #2:
//Space Complexity: O(1)
// Time Complexity: O(m*n)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int numBattleships = 0;
        
        for(unsigned int i = 0; i < board.size(); i++){
            for(unsigned int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.') continue;
                
                if(i > 0 && board[i - 1][j] == 'X') continue;
                
                if(j > 0 && board[i][j - 1] == 'X') continue;
                
                numBattleships++;
            }
        }
        
        return numBattleships;
    }
};