// Space complexity: O(N) - 8.5 MB, less than 75.04% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefixSum(nums.size());
        
        prefixSum[0] = nums[0];
        
        for(int i = 1; i < (int)nums.size(); i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        return prefixSum;
    }
};
