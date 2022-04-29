// Space complexity: O(N*M) - 23.2 MB, less than 66.14% of C++ online submissions
//  Time complexity: O(N*M) - 19 ms, faster than 82.47% of C++ online submissions
class Solution {
public:
    void sinkIsland(vector<vector<int>> &grid, int x, int y, int &area){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] != 1) return;
        
        grid[x][y] = '.';
        area++;
        
        sinkIsland(grid, x + 1, y, area);
        sinkIsland(grid, x - 1, y, area);
        sinkIsland(grid, x, y + 1, area);
        sinkIsland(grid, x, y - 1, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, curArea;
        
        for(unsigned int row = 0; row < grid.size(); row++){
            for(unsigned int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1){
                    curArea = 0;
                    sinkIsland(grid, row, col, curArea);
                    
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        
        return maxArea;
    }
};
