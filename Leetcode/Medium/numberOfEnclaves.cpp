// Space complexity: O(N*M) - 21.7 MB, less than 86.74% of C++ online submissions
//  Time complexity: O(N*M) - 59 ms, faster than 92.60% of C++ online submissions
class Solution {
public:
    void sink(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        else if(grid[x][y] == 0) return;
        
        grid[x][y] = 0;
        
        sink(grid, x + 1, y);
        sink(grid, x - 1, y);
        sink(grid, x, y + 1);
        sink(grid, x, y - 1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int rows = 0; rows < grid.size(); rows++){
            sink(grid, rows, 0);
            sink(grid, rows, (int)grid[0].size() - 1);
        }
        
        for(int cols = 0; cols < grid[0].size(); cols++){
            sink(grid, 0, cols);
            sink(grid, (int)grid.size() - 1, cols);
        }
        
        for(int rows = 0; rows < grid.size(); rows++){
            for(int cols = 0; cols < grid[0].size(); cols++){
                if(grid[rows][cols] == 1) ans++;
            }
        }
        
        return ans;
    }
};
