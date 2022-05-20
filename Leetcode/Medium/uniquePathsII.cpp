// Space complexity: O(N * M) - 7.9 MB, less than 13.17% of C++ online submissions
//  Time complexity: O(N * M) - 5 ms, faster than 40.74% of C++ online submissions
class Solution {
public:
    typedef long long int lli;
    
    lli backtracking(vector<vector<int>> &obstacleGrid, vector<vector<lli>> &dp, int x, int y){
        if(x < 0 || x >= obstacleGrid.size() || y < 0 || y >= obstacleGrid[0].size() ||
           obstacleGrid[x][y] == 1) return 0ll;
        if(dp[x][y] != -1ll) return dp[x][y];
        
        dp[x][y] = 0ll;
        
        dp[x][y] += backtracking(obstacleGrid, dp, x + 1, y) +
                    backtracking(obstacleGrid, dp, x, y + 1);
        
        return dp[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        vector<vector<lli>> dp(obstacleGrid.size(), vector<lli>(obstacleGrid[0].size(), -1ll));
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;    
        else dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] = 1ll;
        
        for(unsigned int row = 0; row < obstacleGrid.size(); row++){
            for(unsigned int col = 0; col < obstacleGrid[0].size(); col++){
                backtracking(obstacleGrid, dp, row, col);
            }
        }
        
        return dp[0][0];
    }
};
