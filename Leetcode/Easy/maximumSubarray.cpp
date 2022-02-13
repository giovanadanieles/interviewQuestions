// Space complexity: O(1) - less than 91.27% of C++ online submissions
//  Time complexity: O(N) - faster than 55.81% of C++ online submissions
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrent, maxGlobal;
        
        maxCurrent = maxGlobal = nums[0];
        
        for(unsigned int i = 1; i < nums.size(); i++){
            maxCurrent = max(maxCurrent + nums[i], nums[i]);
            
            if(maxCurrent > maxGlobal) maxGlobal = maxCurrent;
        }
        
        return maxGlobal;
    }
};
