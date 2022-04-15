// Ref: https://www.youtube.com/watch?v=cQX3yHS0cLo

// Space complexity: O(N) - 6.3 MB, less than 46.20% of C++ online submissions
//  Time complexity: O(N) - 2 ms, faster than 56.36% of C++ online submissions
// class Solution {
// public:
//     int numDecodings(string s) {
//         int oneDigit, twoDigits;
//         vector<int> dp(s.size() + 1); // num of ways to decode a string of size X
        
//         dp[0] = 1; // there's no way, that's a way
//         dp[1] = s[0] == '0' ? 0 : 1;
        
//         for(unsigned int i = 2; i <= s.size(); i++){
//             oneDigit = s[i - 1] - '0';
//             twoDigits = (s[i - 2] - '0') * 10 + oneDigit;
                        
//             if(oneDigit >= 1) dp[i] += dp[i - 1];
//             if(twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i - 2];
//         }
        
//         return dp[s.size()];
//     }
// };



// Space complexity: O(1) - 6.2 MB, less than 46.20% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 39.04% of C++ online submissions
class Solution {
public:
    int numDecodings(string s) {
        int oneDigit, twoDigits, firstPrev, secPrev, curr = 0;
        
        secPrev = 1;
        firstPrev = s[0] == '0' ? 0 : 1;
        
        for(unsigned int i = 2; i <= s.size(); i++){
            oneDigit = s[i - 1] - '0';
            twoDigits = (s[i - 2] - '0') * 10 + oneDigit;
                        
            if(oneDigit >= 1) curr += firstPrev;
            if(twoDigits >= 10 && twoDigits <= 26) curr += secPrev;
            
            secPrev = firstPrev;
            firstPrev = curr;
            curr = 0;
        }
        
        return firstPrev;
    }
};
