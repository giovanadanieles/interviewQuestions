// Ref: https://www.youtube.com/watch?v=Ph95IHmRp5M
// Space complexity: O(N) - 9.3 MB, less than 28.23% of C++ online submissions
//  Time complexity: O(N^N) - 22 ms, faster than 29.61% of C++ online submissions
class Solution {
public:
    /* posDiag = r + c
       negDiag = r - c
    */
    
    unordered_set<int> usedCol, usedPosDiag, usedNegDiag;
    vector<vector<string>> ans;
    
    void backtracking(vector<string> &board, int numOfQueens, int row){
        if(row == numOfQueens){
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < numOfQueens; col++){
            if(usedCol.find(col) == usedCol.end() && usedPosDiag.find(row + col) == usedPosDiag.end() &&
               usedNegDiag.find(row - col) == usedNegDiag.end()){
                
                usedCol.insert(col), usedPosDiag.insert(row + col), usedNegDiag.insert(row - col);
                board[row][col] = 'Q';
                
                backtracking(board, numOfQueens, row + 1);
                
                usedCol.erase(col), usedPosDiag.erase(row + col), usedNegDiag.erase(row - col);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        backtracking(board, n, 0);
        
        return ans;
    }
};
