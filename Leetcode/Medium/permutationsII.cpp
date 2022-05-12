// Space complexity: O(N) or O(N * N!) - 9.5 MB, less than 49.48% of C++ online submissions
//  Time complexity: O(N!) - 35 ms, faster than 29.54% of C++ online submissions
// class Solution {
// public:
//     vector<int> curPermutation;
    
//     struct hashFunction{
//         size_t operator()(const vector<int> &vec) const{
//             hash<int> hasher;
//             size_t answer = 0;
      
//             for(int i : vec){
//               answer ^= hasher(i) + 0x9e3779b9 + (answer << 6) + (answer >> 2);
//             }
            
//             return answer;
//         }
//     };
    
//     void backtracking(unordered_set<vector<int>, hashFunction> &permutations, vector<int> &nums, vector<bool> &visited){
//         if(curPermutation.size() == nums.size()){
//             permutations.insert(curPermutation);
//             return;
//         }
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             if(visited[i] == false){
//                 visited[i] = true;
//                 curPermutation.push_back(nums[i]);

//                 backtracking(permutations, nums, visited);

//                 curPermutation.pop_back();
//                 visited[i] = false;
//             }
//         }
//     }
    
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<bool> visited(nums.size(), false);
//         unordered_set<vector<int>, hashFunction> permutations;
//         vector<vector<int>> ans;
        
//         backtracking(permutations, nums, visited);
        
//         for(auto it: permutations) ans.push_back(it);
        
//         return ans;
//     }
// };



// Space complexity: O(N) or O(N * N!) - 8.5 MB, less than 81.01% of C++ online submissions
//  Time complexity: O(N!) - 8 ms, faster than 74.77% of C++ online submissions
class Solution {
public:
    vector<int> curPermutation;

    void backtracking(vector<vector<int>> &permutations, vector<int> &nums, unordered_map<int, int> &freq){
        if(curPermutation.size() == nums.size()){
            permutations.push_back(curPermutation);
            return;
        }
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second > 0){
                it->second--;
                curPermutation.push_back(it->first);

                backtracking(permutations, nums, freq);

                curPermutation.pop_back();
                it->second += 1;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /*
        * A key insight to avoid generating any redundant permutation is that at each step rather than
        * viewing each number as a candidate, we consider each unique number as the true candidate. For 
        * instance, at the very beginning, given in the input of [1, 1, 2], we have only two true candidates
        * instead of three.
        */
        
        unordered_map<int, int> freq;
        vector<vector<int>> permutations;
        
        for(int i : nums) freq[i]++;
        
        backtracking(permutations, nums, freq);
        
        return permutations;
    }
};
