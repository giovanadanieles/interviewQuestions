// Space complexity: O(N) - less than 85.44% of C++ online submissions
//  Time complexity: O(2 ^ N) - faster than 57.43% of C++ online submissions
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(unsigned int curIndex, vector<int>& nums){
        if(curIndex >= nums.size()){
            ans.push_back(subset);
            
            return;
        }
        
        //include
        subset.push_back(nums[curIndex]);
        dfs(curIndex + 1, nums);
        
        //do not include
        subset.pop_back();
        dfs(curIndex + 1, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        
        return ans;
    }
};
