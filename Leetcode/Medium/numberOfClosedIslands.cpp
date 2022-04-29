// Space complexity: O(N * M) - 9.5 MB, less than 66.83% of C++ online submissions
//  Time complexity: O(N * M) - faster than 89.43% of C++ online submissions
class Solution {
public:
    void sink(vector<vector<int>> &grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == 1 || grid[x][y] == -1) return;
        
        grid[x][y] = -1;
        
        sink(grid, x + 1, y);
        sink(grid, x - 1, y);
        sink(grid, x, y + 1);
        sink(grid, x, y - 1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int numOfClosedIslands = 0;
        
        //Excluding connected group of 0s on the corners
        for(unsigned int col = 0; col < grid[0].size(); col++){
            if(grid[0][col] == 0) sink(grid, 0, col);
            if(grid[grid.size() - 1][col] == 0) sink(grid, grid.size() - 1, col);
        }
        
        for(unsigned int row = 0; row < grid.size(); row++){
            if(grid[row][0] == 0) sink(grid, row, 0);
            if(grid[row][grid[0].size() - 1] == 0) sink(grid, row, grid[0].size() - 1);
        }
        
        // Counting number of connected component of 0s
        for(unsigned int row = 0; row < grid.size(); row++){
            for(unsigned int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == 0){
                    numOfClosedIslands++;
                    sink(grid, row, col);
                }
            }
        }
        
        return numOfClosedIslands;
    }
};
