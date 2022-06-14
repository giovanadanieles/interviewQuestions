// Ref: https://www.youtube.com/watch?v=OM1MTokvxs4
// Space complexity: O(N) - 8.6 MB, less than 64.49% of C++ online submissions
//  Time complexity: O(N^2) - 9 ms, faster than 51.86% of C++ online submissions
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size() - 1].size() + 1, 0);
        
        for(int level = (int)triangle.size() - 1; level >= 0; level--){
            for(int index = 0; index < triangle[level].size(); index++){
                dp[index] = triangle[level][index] + min(dp[index], dp[index + 1]);
            }
        }
        
        return dp[0];
    }
};
