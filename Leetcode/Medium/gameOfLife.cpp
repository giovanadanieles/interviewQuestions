// Space complexity: O(N * M) - 7 MB, less than 58.55% of C++ online submissions
//  Time complexity: O(N * M) - 8 ms, faster than 5.66% of C++ online submissions
// class Solution {
// public:
//     int countNeighbors(vector<vector<int>>& board, int x, int y){
//         bool top = false, bottom = false, left = false, right = false;
//         int numOfNeigh = 0;
        
//         if(x + 1 < board.size()){
//             bottom = true;
//             if(board[x + 1][y] == 1) numOfNeigh++;
//         }
//         if(x - 1 >= 0){
//             top = true;
//             if(board[x - 1][y] == 1) numOfNeigh++;
//         }
//         if(y + 1 < board[x].size()){
//             right = true;
//             if(board[x][y + 1] == 1) numOfNeigh++;
//         }
//         if(y - 1 >= 0){
//             left = true;
//             if(board[x][y - 1] == 1) numOfNeigh++;
//         }
                
//         if(bottom && left && board[x + 1][y - 1] == 1) numOfNeigh++;
//         if(bottom && right && board[x + 1][y + 1] == 1) numOfNeigh++;
//         if(top && left && board[x - 1][y - 1] == 1) numOfNeigh++;
//         if(top && right && board[x - 1][y + 1] == 1) numOfNeigh++;
        
//         return numOfNeigh;
//     }
    
//     void gameOfLife(vector<vector<int>>& board){
//         int numOfNeigh;
//         vector<vector<int>> nextStage = board;
        
//         for(unsigned int x = 0; x < board.size(); x++){
//             for(unsigned int y = 0; y < board[x].size(); y++){
//                 numOfNeigh = countNeighbors(board, x, y);
                                
//                 if(board[x][y] == 1){
//                     if(numOfNeigh < 2 || numOfNeigh > 3) nextStage[x][y] = 0;
//                 }
//                 else{
//                     if(numOfNeigh == 3) nextStage[x][y] = 1;
//                 }
//             }
//         }
        
//         board = nextStage;
//     }
// };



// Space complexity: O(1)  - 6.9 MB, less than 84.44% of C++ online submissions
//  Time complexity: O(N * M) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public: 
    int countNeighbors(vector<vector<int>>& board, int x, int y){
        bool top = false, bottom = false, left = false, right = false;
        int numOfNeigh = 0;
        
        if(x + 1 < board.size()){
            bottom = true;
            if(board[x + 1][y] == 1 || board[x + 1][y] == 3) numOfNeigh++;
        }
        if(x - 1 >= 0){
            top = true;
            if(board[x - 1][y] == 1 || board[x - 1][y] == 3) numOfNeigh++;
        }
        if(y + 1 < board[x].size()){
            right = true;
            if(board[x][y + 1] == 1 || board[x][y + 1] == 3) numOfNeigh++;
        }
        if(y - 1 >= 0){
            left = true;
            if(board[x][y - 1] == 1 || board[x][y - 1] == 3) numOfNeigh++;
        }
                
        if(bottom && left && (board[x + 1][y - 1] == 1 || board[x + 1][y - 1] == 3)) numOfNeigh++;
        if(bottom && right && (board[x + 1][y + 1] == 1 || board[x + 1][y + 1] == 3)) numOfNeigh++;
        if(top && left && (board[x - 1][y - 1] == 1 || board[x - 1][y - 1] == 3)) numOfNeigh++;
        if(top && right && (board[x - 1][y + 1] == 1 || board[x - 1][y + 1] == 3)) numOfNeigh++;
        
        return numOfNeigh;
    }
    
    void gameOfLife (vector<vector<int>>& board){
        int numOfNeighs;
        
        /*
        *    original | new | value
        *       0     |  0  |   0
        *       1     |  0  |   1
        *       0     |  1  |   2
        *       1     |  1  |   3
        */
        
        for(unsigned int x = 0; x < board.size(); x++){
            for(unsigned int y = 0; y < board[x].size(); y++){
                numOfNeighs = countNeighbors(board, x, y);
                
                if(board[x][y] == 1){
                    if(numOfNeighs == 2 || numOfNeighs == 3) board[x][y] = 3;
                }
                else if(numOfNeighs == 3) board[x][y] = 2;
            }
        }
        
        for(unsigned int x = 0; x < board.size(); x++){
            for(unsigned int y = 0; y < board[x].size(); y++){
                if(board[x][y] == 1) board[x][y] = 0;
                else if(board[x][y] == 2 || board[x][y] == 3) board[x][y] = 1;
            }
        }
    }
};
