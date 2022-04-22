// Ref: https://www.youtube.com/watch?v=cjWnW0hdF1Y

// Space complexity: O(N) - 10.4 MB, less than 87.64% of C++ online submissions
//  Time complexity: O(N ^ 2) - 350 ms, faster than 41.05% of C++ online submissions
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 0;
        vector<int> lis(nums.size(), 1);
        
        for(int i = nums.size() - 1; i >= 0; i--){
            for(unsigned int j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j]) lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
        
        for(unsigned int i = 0; i < lis.size(); i++) maxLength = max(maxLength, lis[i]);
        
        return maxLength;
    }
};
