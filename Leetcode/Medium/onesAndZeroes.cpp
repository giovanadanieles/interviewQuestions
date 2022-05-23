// TIME LIMIT EXCEEDED :(
// Space complexity: O(L)
//  Time complexity: O(2^L)
// class Solution {
// public:
//     int maxSize = 0;
    
//     void backtracking(vector<string>& strs, int curIndex, vector<string> &subset, int m, int n){
//         if(curIndex == strs.size()){
//             for(unsigned int i = 0; i < subset.size(); i++){
//                 for(char c : subset[i]){
//                     if(c == '0') m--;
//                     else n--;
//                 }
//             }
            
//             if(m >= 0 && n >= 0) maxSize = max(maxSize, (int)subset.size());
            
//             return;
//         }
        
//         subset.push_back(strs[curIndex]);
//         backtracking(strs, curIndex + 1, subset, m, n);
        
//         subset.pop_back();
//         backtracking(strs, curIndex + 1, subset, m, n);
//     }
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<string> subset;
        
//         backtracking(strs, 0, subset, m, n);
        
//         return maxSize;
//     }
// };



// Ref: https://leetcode.com/problems/ones-and-zeroes/discuss/814077/Dedicated-to-Beginners
// Space complexity: O(L * M * N) - 35.7 MB, less than 47.01% of C++ online submissions
//  Time complexity: O(L * M * N) - 521 ms, faster than 31.26% of C++ online submissions
class Solution {
public:
    int dp[601][101][101] = {};
    
    int backtracking(vector<pair<int, int>> &zeroAndOneQtt, int curIndex, int nZeroes, int nOnes){
        if(curIndex == zeroAndOneQtt.size() || nOnes + nZeroes == 0) return 0;
        // if we already know answer for this index with current (nZeroes,nOnes) then no need 
        //to recompute return the saved answer
        else if(dp[curIndex][nZeroes][nOnes] != -1) return dp[curIndex][nZeroes][nOnes]; 
        
        // we dont have available no of zeros or ones to build this curent string, so we dont 
        //have any other option but to skip this index
        if(zeroAndOneQtt[curIndex].first > nZeroes || zeroAndOneQtt[curIndex].second > nOnes)  
            return dp[curIndex][nZeroes][nOnes] = backtracking(zeroAndOneQtt , curIndex + 1 , nZeroes , nOnes);
        //  |-> NOTE : we are also saving corrensponding values
        
        int include = 1 + backtracking(zeroAndOneQtt , curIndex + 1, nZeroes - zeroAndOneQtt[curIndex].first , nOnes -                               zeroAndOneQtt[curIndex].second);
        int exclude = backtracking(zeroAndOneQtt , curIndex + 1 , nZeroes , nOnes);
        
        // save these values and return the answer
        return dp[curIndex][nZeroes][nOnes] = max(include , exclude);
    }
        
    int findMaxForm(vector<string>& strs, int m, int n) {
        int zeroes, ones, ans;
        vector<pair<int, int>> zeroAndOneQtt;
        
        memset(dp , -1 , sizeof(dp));
        
        for(unsigned int i = 0; i < strs.size(); i++){
            zeroes = 0, ones = 0;
            
            for(char c : strs[i]) c == '0' ? zeroes++ : ones++;
            
            zeroAndOneQtt.push_back({zeroes, ones});
        }

        return backtracking(zeroAndOneQtt, 0 , m , n);
    }
};
