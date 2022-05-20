// Ref: https://www.youtube.com/watch?v=H9bfqozjoqs

// Space complexity: O(A) - 14.4 MB, less than 54.73% of C++ online submissions
//  Time complexity: O(A * C) - 102 ms, faster than 63.90% of C++ online submissions
class Solution {
public:    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0;
        
        for(int value = 1; value <= amount; value++){
            for(auto coin : coins){
                if(value - coin >= 0) dp[value] = min(dp[value], 1 + dp[value - coin]);
            }
        }
        
        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};
