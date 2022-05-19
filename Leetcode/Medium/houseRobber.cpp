// Space complexity: O(1) - 7.6 MB, less than 76.62% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 33.56% of C++ online submissions
class Solution {
public:
    int rob(vector<int>& nums) {        
        for(int i = (int)nums.size() - 1; i >= 0; i--){
            if(i + 2 < nums.size()) nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
            else if(i + 1 < nums.size()) nums[i] = max(nums[i], nums[i + 1]);
        }
        
        return nums[0];
    }
};
