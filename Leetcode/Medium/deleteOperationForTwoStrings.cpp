// Ref: https://www.youtube.com/watch?v=2XDYkFz9uSc
// Space complexity: O(N*M) - 12.1 MB, less than 54.34% of C++ online submissions
//  Time complexity: O(N*M) - 22 ms, faster than 69.18% of C++ online submissions
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            DP Approach:
            
               " a b c
            "  0 1 2 3
            c  1 2 3 2
            b  2 3 2 3
            a  3 2 3 4
            
            -> if curVertical = curHorizontal, we get the value from [row-1][col-1]
            -> otherwise, curVal = min([row-1][col], [row][col-1]) + 1
        
        */
        
        vector<vector<int>> dp(word2.size() + 1, vector<int>(word1.size() + 1, 0));
        
        for(int col = 0; col <= word1.size(); col++){
            dp[0][col] = col;
        }
        
        for(int row = 0; row <= word2.size(); row++){
            dp[row][0] = row;
        }
        
        for(int row = 1; row <= word2.size(); row++){
            for(int col = 1; col <= word1.size(); col++){
                if(word1[col - 1] == word2[row - 1]){
                    dp[row][col] = dp[row - 1][col - 1];
                }
                else{
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }
        
        return dp[word2.size()][word1.size()];
    }
};
