// Space complexity: O(1) - 96.3 MB, less than 56.59% of C++ online submissions
//  Time complexity: O(N * M) - 164 ms, faster than 41.41% of C++ online submissions
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for(unsigned int row = 0; row < grid.size(); row++){
            for(unsigned int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1){
                    perimeter += 4;
                    
                    if(col > 0 && grid[row][col - 1] == 1) perimeter--;
                    if(row > 0 && grid[row - 1][col] == 1) perimeter--;
                    if(col < grid[row].size() - 1 && grid[row][col + 1] == 1) perimeter--;
                    if(row < grid.size() - 1 && grid[row + 1][col] == 1) perimeter--;
                }
            }
        }
        
        return perimeter;
    }
};
