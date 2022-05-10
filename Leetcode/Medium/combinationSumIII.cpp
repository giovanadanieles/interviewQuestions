// Space complexity: (9! / (9-k)!) - 6.6 MB, less than 37.26% of C++ online submission
//  Time complexity: (k) - 337 ms, faster than 5.36% of C++ online submissions
// class Solution {
// public:
//     vector<int> curCombination;
//     unordered_set<vector<bool>> combAlreadyExists;
    
//     void backtracking(vector<bool> &digitsInUse, vector<vector<int>> &allCombinations, int curSum, int targetSum, int qtt){
//         if(curCombination.size() == qtt){
//             if(curSum == targetSum){
//                 if(combAlreadyExists.find(digitsInUse) == combAlreadyExists.end()){
//                     allCombinations.push_back(curCombination);
//                     combAlreadyExists.insert(digitsInUse);
//                 }
//             }
            
//             return;
//         }
        
//         for(unsigned int i = 0; i < digitsInUse.size(); i++){
//             if(digitsInUse[i] == false){
//                 digitsInUse[i] = true;
//                 curCombination.push_back(i + 1);
                
//                 backtracking(digitsInUse, allCombinations, curSum + i + 1, targetSum, qtt);
                
//                 digitsInUse[i] = false;
//                 curCombination.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<bool> digitsInUse(9, false);
//         vector<vector<int>> allCombinations;
        
//         backtracking(digitsInUse, allCombinations, 0, n, k);
            
//         return allCombinations;
//     }
// };



// Ref: https://www.youtube.com/watch?v=LoycI7Y-hww
// Space complexity: O(9! / ((9 - k)! k!)) - 6.5 MB, less than 58.80% of C++ online submissions
//  Time complexity: O(k) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<int> curCombination;
    
    void backtracking(vector<vector<int>> &allCombinations, int curSum, int targetSum, int curNum, int qtt){
        if(curCombination.size() == qtt){
            if(curSum == targetSum) allCombinations.push_back(curCombination);
            return;
        }
        
        for(int i = curNum; i <= 9; i++){
            if(curSum + 1 > targetSum) break;
            
            curCombination.push_back(i);
            backtracking(allCombinations, curSum + i, targetSum, i + 1, qtt);
            curCombination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allCombinations;
        
        backtracking(allCombinations, 0, n, 1, k);
            
        return allCombinations;
    }
};
