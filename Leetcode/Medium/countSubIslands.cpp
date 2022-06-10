// Space complexity: O(N*M) - 91.2 MB, less than 51.85% of C++ online submissions
//  Time complexity: O(N*M) - 921 ms, faster than 5.00% of C++ online submissions
// class Solution {
// public:
//     void findSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y, bool &isSubIsland){
//         if(x < 0 || x >= grid2.size() || y < 0 || y >= grid2[0].size()) return;
//         if(grid2[x][y] == 0) return;
        
//         if(grid1[x][y] == 0) isSubIsland = false;
        
//         grid2[x][y] = 0;
        
//         findSubIslands(grid1, grid2, x + 1, y, isSubIsland);
//         findSubIslands(grid1, grid2, x - 1, y, isSubIsland);
//         findSubIslands(grid1, grid2, x, y + 1, isSubIsland);
//         findSubIslands(grid1, grid2, x, y - 1, isSubIsland);
//     }
    
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         bool isSubIsland;
//         int subIslands = 0;
        
//         for(unsigned int row = 0; row < grid2.size(); row++){
//             for(unsigned int col = 0;  col < grid2[0].size(); col++){
//                 if(grid2[row][col] == 1){
//                     isSubIsland = true;
                    
//                     findSubIslands(grid1, grid2, row, col, isSubIsland);
                    
//                     subIslands += isSubIsland;
                    
//                     if(isSubIsland) cout << row << "x" << col << endl;
//                 }
//             }
//         }
        
//         return subIslands;
//     }
// };



// Space complexity: O(N*M) - 88.5 MB, less than 85.16% of C++ online submissions
//  Time complexity: O(N*M) - 361 ms, faster than 77.59% of C++ online submissions
class Solution {
public:
    void sink(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y){
        if(x < 0 || x >= grid2.size() || y < 0 || y >= grid2[0].size()) return;
        if(grid2[x][y] == 0) return;
        
        grid2[x][y] = 0;
        
        sink(grid1, grid2, x + 1, y);
        sink(grid1, grid2, x - 1, y);
        sink(grid1, grid2, x, y + 1);
        sink(grid1, grid2, x, y - 1);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands = 0;
        
        // Removing all the non-common sub-islands
        for(unsigned int row = 0; row < grid2.size(); row++){
            for(unsigned int col = 0;  col < grid2[0].size(); col++){
               if(grid1[row][col] == 0 && grid2[row][col] == 1){
                   sink(grid1, grid2, row, col);
               }
            }
        }
        
        // Counting sub-islands
        for(unsigned int row = 0; row < grid2.size(); row++){
            for(unsigned int col = 0;  col < grid2[0].size(); col++){
               if(grid2[row][col] == 1){
                   sink(grid1, grid2, row, col);
                   
                   subIslands++;
               }
            }
        }
        
        return subIslands;
    }
};
