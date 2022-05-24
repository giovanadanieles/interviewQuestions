// Ref: https://www.youtube.com/watch?v=xxvPcn9eoS0

// Space complexity: O(1) - 14.9 MB, less than 69.47% of C++ online submissions
//  Time complexity: O(N + M) - 152 ms, faster than 49.92% of C++ online submissions
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col, curRow, curCol;
        
        row = (int)matrix.size(), col = (int)matrix[0].size();
        curRow = row - 1, curCol = 0;
        
        while(curRow >= 0 && curCol < col){
            if(matrix[curRow][curCol] < target) curCol++;
            else if(matrix[curRow][curCol] > target) curRow--;
            else return true;
        }
        
        return false;
    }
};
