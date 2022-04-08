// Ref: https://leetcode.com/problems/last-stone-weight-ii/discuss/653550/Trying-to-Explain-A-bit-(logic-behind-trick)

// Space complexity: O(N * sum(stones)) - 9.4 MB, less than 26.48% of C++ online submissions
//  Time complexity: O(N * sum(stones)) - 7 ms, faster than 64.32% of C++ online submissions
class Solution {
public:
    /*  
        *  Approach: find two subarrays and minimize the difference between the "smashed sum" of them
        *  
        *   Ex: [2, 7, 4, 1, 8, 1]
        *
        *     Possible division: S1 = [2, 1, 8]  S2 = [4, 1, 7]; sum = 1
        *     Another possibility: S1 = [2, 7, 1] S2 = [4, 8, 1]; sum = 3 
        *
        *   The answer is 1.
    */
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0, maxSum, numElements;
        
        numElements = stones.size();
        
        for(unsigned int i = 0; i < numElements; i++) total += stones[i];
        maxSum = total / 2;
                
        // dp[i][j] = maximum sum M <= j I can get in the range [0, i]
        vector<vector<int>> dp(numElements + 1, vector<int>(maxSum + 1, 0));
        
        for(unsigned int i = 1; i <= numElements; i++){
            for(unsigned int j = 1; j <= maxSum; j++){
                if(stones[i - 1] > j) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
    
        return total - 2 * dp[numElements][maxSum];
    }
};
