class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unsigned int numOfIslands = 0;
        
        for(unsigned int i = 0; i < grid.size(); i++){
            for(unsigned int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    numOfIslands++;
                    
                    sink(i, j, grid);
                }
            }
        }
        
        return numOfIslands;
    }
    
    void sink(unsigned int x, unsigned int y, vector<vector<char>>& grid){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] == '0') return;
        
        grid[x][y] = '0';
        sink(x + 1, y, grid);
        sink(x - 1, y, grid);
        sink(x, y + 1, grid);
        sink(x, y - 1, grid);
    }
};