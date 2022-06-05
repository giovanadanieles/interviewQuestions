// Space complexity: O(N) - 12.5 MB, less than 16.33% of C++ online submissions
//  Time complexity: O(N^N) - 18 ms, faster than 25.73% of C++ online submissions
class Solution {
public:
    unordered_set<int> usedCol, usedPosDiag, usedNegDiag;
    
    void backtracking(vector<string> board, int numberOfQueens, int row, int &ans){
        if(row == numberOfQueens){
            ans++;
            return;
        }
        
        for(int col = 0; col < numberOfQueens; col++){
            if(usedCol.find(col) == usedCol.end() && usedPosDiag.find(row + col) == usedPosDiag.end() &&
               usedNegDiag.find(row - col) == usedNegDiag.end()){
                
                usedCol.insert(col), usedPosDiag.insert(row + col), usedNegDiag.insert(row - col);
                board[row][col] = 'Q';
                
                backtracking(board, numberOfQueens, row + 1, ans);
                
                usedCol.erase(col), usedPosDiag.erase(row + col), usedNegDiag.erase(row - col);
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        
        backtracking(board, n, 0, ans);
        
        return ans;
    }
};
