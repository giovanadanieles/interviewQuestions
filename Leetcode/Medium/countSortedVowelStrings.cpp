// 1. BACKTRACKING APPROACH
// Space complexity: O(N^5) - 5.9 MB, less than 58.59% of C++ online submissions
//  Time complexity: O(N) - 85 ms, faster than 10.82% of C++ online submissions
// class Solution {
// public: 
//     void backtracking(int curVowel, int curSize, int strSize, int &count){
//         if(curSize == strSize){
//             count++;
//             return;
//         }
        
//         for(int i = curVowel; i < 5; i++){
//             if(curSize + 1 > strSize) break;
//             else backtracking(i, curSize + 1, strSize, count);
//         }
//     }
    
//     int countVowelStrings(int n) {
//         int ans = 0;
        
//         backtracking(0, 0, n, ans);
        
//         return ans;
//     }
// };



// 2. DP APPROACH
// Space complexity: O(N * K), being K = 5 - 6.5 MB, less than 11.82% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 35.53% of C++ online submissions
// class Solution {
// public: 
//     int countVowelStrings(int n) {
//         int ans = 0;
//         vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
//         for(unsigned int i = 0; i < 5; i++) dp[0][i] = 1;
        
//         for(unsigned int i = 1; i < n; i++){
//             dp[i][0] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]; // a
//             dp[i][1] += dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]; // e
//             dp[i][2] += dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]; // i
//             dp[i][3] += dp[i - 1][3] + dp[i - 1][4]; // o
//             dp[i][4] += dp[i - 1][4]; // u
//         }
        
//         for(unsigned int i = 0; i < 5; i++) ans += dp[n - 1][i];
        
//         return ans;
//     }
// };



// 3. MATH APPROACH
// Space complexity: O(1) - 5.9 MB, less than 58.59% of C++ online submissions
//  Time complexity: O(1) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public: 
    int countVowelStrings(int n) {
        // combination with repetition (order doesn't matter) = (n + p - 1)! / (p! (n-1)!)
        //                                                    = (5 + n - 1)! / (n! (4)!)
        return ((n + 4) * (n + 3) * (n + 2) * (n + 1) / 24);
    }
};
