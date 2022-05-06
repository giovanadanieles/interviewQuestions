// Space complexity: O(N!) - 8 MB, less than 38.27% of C++ online submissions
//  Time complexity: O(N!), or O(N) [without output] - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:    
    vector<int> permutation;
    vector<vector<int>> allPermutations;
    
    void backtracking(vector<int> &nums, vector<bool> &visited){
        if(permutation.size() == nums.size()){
            allPermutations.push_back(permutation);
            return;
        }
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(visited[i + 10] == false){
                visited[i + 10] = true;
                
                permutation.push_back(nums[i]);
                backtracking(nums, visited);
                
                permutation.pop_back();
                visited[i + 10] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(20, false);
        
        backtracking(nums, visited);
        
        return allPermutations;
    }
};
