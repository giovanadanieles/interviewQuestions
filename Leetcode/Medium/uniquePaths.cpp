// BACKTRACKING APPROACH - TLE
// class Solution {
// public:
//     int paths = 0;
    
//     void findingPaths(int m, int n, int x, int y){
//         if(x >= m || y >= n) return;
//         if(x == m - 1 && y == n - 1){
//             paths++;
//             return;
//         }
        
//         findingPaths(m, n, x + 1, y);
//         findingPaths(m, n, x, y + 1);
//     }
    
//     int uniquePaths(int m, int n) {
//         findingPaths(m, n, 0, 0);
        
//         return paths;
//     }
// };



// DP RECURSIVE APPROACH - Ref: https://www.youtube.com/watch?v=IlEsdxuD4lY
// Space complexity: O(M * N) - 6.5 MB, less than 26.00% of C++ online submissions
//  Time complexity: O(M * N) - 3 ms, faster than 35.61% of C++ online submissions
// class Solution {
// public:    
//     int findingPaths(int m, int n, int x, int y, vector<vector<int>> &dp){
//         if(x >= m || y >= n) return 0;
//         if(dp[x][y] != 0) return dp[x][y];
        
//         int down = findingPaths(m, n, x + 1, y, dp);
//         int right = findingPaths(m, n, x, y + 1, dp);
        
//         dp[x][y] = down + right;
        
//         return dp[x][y];
//     }
    
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
        
//         dp[m - 1][n - 1] = 1;
        
//         findingPaths(m, n, 0, 0, dp);
        
//         return dp[0][0];
//     }
// };



// DP ITERATIVE APPROACH
// Space complexity: O(M * N) - 6.5 MB, less than 26.00% of C++ online submissions
//  Time complexity: O(M * N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(x != 0) dp[x][y] += dp[x - 1][y];
                if(y != 0) dp[x][y] += dp[x][y - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
