// Space complexity: O(1) - less than 83.01% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    int climbStairs(int n) {
        int ans, cur, prev1, prev2;
        
        if(n == 1 || n == 2) return n;
        
        prev1 = 1, prev2 = 2, cur = 3;
        do{
            ans = prev1 + prev2;
                        
            prev1 = prev2;
            prev2 = ans;
                        
            cur++;
        } while(cur <= n);
        
        return ans;
    }
};
