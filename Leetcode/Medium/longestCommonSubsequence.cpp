// Ref: https://www.youtube.com/watch?v=Ua0GhsJSlWM

// Space complexity: O(N * M) - 13.1 MB, less than 19.12% of C++ online submissions
//  Time complexity: O(N * M) - 26 ms, faster than 56.60% of C++ online submissions
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(int i = text1.size() - 1; i >= 0; i--){
            for(int j = text2.size() - 1; j >= 0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        
        return dp[0][0];
    }
};
