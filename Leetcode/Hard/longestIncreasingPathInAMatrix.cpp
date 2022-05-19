// Space complexity: O(N * M) - 16.5 MB, less than 37.33% of C++ online submissions
//  Time complexity: O(N * M) - 67 ms, faster than 48.95% of C++ online submissions
class Solution {
public:    
    int backtracking(vector<vector<int>> &matrix, vector<vector<int>> &dp, vector<vector<bool>> &visited, int x, int y, int prevVal, int &maxPathSize){
        if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] <= prevVal) return 0;
        else if(visited[x][y] == true) return dp[x][y];
        
        visited[x][y] = true;
        
        int top = backtracking(matrix, dp, visited, x + 1, y, matrix[x][y], maxPathSize);
        int bottom = backtracking(matrix, dp, visited, x - 1, y, matrix[x][y], maxPathSize);
        int left = backtracking(matrix, dp, visited, x, y + 1, matrix[x][y], maxPathSize);
        int right = backtracking(matrix, dp, visited, x, y - 1, matrix[x][y], maxPathSize);
                
        dp[x][y] += max({top, bottom, left, right});
        
        maxPathSize = max(dp[x][y], maxPathSize);
        
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix){   
        int maxPathSize = INT_MIN;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        for(unsigned int row = 0; row < matrix.size(); row++){
            for(unsigned int col = 0; col < matrix[0].size(); col++){
                backtracking(matrix, dp, visited, row, col, -1, maxPathSize);
            }
        }
                
        return maxPathSize;
    }
};
