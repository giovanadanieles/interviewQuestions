// Ref: https://www.youtube.com/watch?v=Sx9NNgInc3A

// Space complexity: O(S) - 7.8 MB, less than 85.58% of C++ online submissions
//  Time complexity: O(S * W * W_len) - 8 ms, faster than 73.38% of C++ online submissions
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        /*
        *   Bottom-up approach: from the end to the begin, we verify if any word
        *  in the wordDic can be found in the substr(i, word.size()). If it can be
        *  be found, dp[i] = dp[i + word.size()] (cause we need to know if, starting
        *  in this end position, there's another word that can be found in wordDict).
        */
        
        vector<int> dp(s.size() + 1, false);
        
        dp[s.size()] = true;
        
        for(int i = s.size(); i >= 0; i--){
            for(string word : wordDict){
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word){
                    dp[i] = dp[i + word.size()];
                }
                
                if(dp[i] == true) break;
            }
        }
        
        return dp[0];
    }
};
