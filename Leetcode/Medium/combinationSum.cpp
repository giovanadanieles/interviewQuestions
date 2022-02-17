// Space complexity: O(3 ^ target) - less than 45.34% of C++ online submissions
//  Time complexity: O(3 ^ target) - faster than 37.51% of C++ online submissions
// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> subset;
//     set<vector<int>> isRepeated;
    
//     void dfs(int curIndex, int curSum, vector<int>& candidates, int target){
//         if(curSum == target){
//             if(isRepeated.find(subset) == isRepeated.end()){
//                 isRepeated.insert(subset);
//                 ans.push_back(subset);
//             }
            
//             return;
//         }
//         if(curSum > target) return;
//         if(curIndex >= candidates.size()) return;
        
//         subset.push_back(candidates[curIndex]);
        
//         //include and do not move
//         dfs(curIndex, curSum + candidates[curIndex], candidates, target);
        
//         //include and move
//         dfs(curIndex + 1, curSum + candidates[curIndex], candidates, target);
        
//         //do not include and move
//         subset.pop_back();
//         dfs(curIndex + 1, curSum, candidates, target);
//     }
    
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         dfs(0, 0, candidates, target);
        
//         return ans;
//     }
// };



// Space complexity: O(2 ^ target) - less than 72.35% of C++ online submissions
//  Time complexity: O(2 ^ target) - faster than 93.36% of C++ online submissions
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    
    void dfs(int curIndex, int curSum, vector<int>& candidates, int target){
        if(curSum == target){
            ans.push_back(subset);
            
            return;
        }
        if(curSum > target || curIndex >= candidates.size()) return;
        
        //include
        subset.push_back(candidates[curIndex]);
        dfs(curIndex, curSum + candidates[curIndex], candidates, target);
        
        //do not include
        subset.pop_back();
        dfs(curIndex + 1, curSum, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, 0, candidates, target);
        
        return ans;
    }
};
