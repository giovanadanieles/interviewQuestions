// Space complexity: O(1) - 16.7 MB, less than 8.83% of C++ online submissions
//  Time complexity: O(N * M * K) - 86 ms, faster than 19.09% of C++ online submissions
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int numRows, numCols, backVal;
        
        numRows = grid.size();
        numCols = grid[0].size();
        
        for(int i = 0; i < k; i++){
            vector<int> lastColumn;
            
            for(int row = 0; row < numRows; row++){
                lastColumn.push_back(grid[row][numCols - 1]);
            }
            
            for(int col = numCols - 2; col >= 0; col--){
                for(int row = 0; row < numRows; row++){                    
                    grid[row][col + 1] = grid[row][col];
                }
            }
            
            backVal = lastColumn.back();
            lastColumn.pop_back();
            lastColumn.insert(lastColumn.begin(), backVal);
            
            for(int row = 0; row < numRows; row++){
                grid[row][0] = lastColumn[row];
            }
        }
        
        return grid;
    }
};
