// Space complexity: O(N) - 7.9 MB, less than 41.50% of C++ online submissions
//  Time complexity: O(N) - 3 ms, faster than 53.42% of C++ online submissions
class Solution {
public:
    int robbingHouses(vector<int> &nums){
         for(int i = (int)nums.size() - 1; i >= 0; i--){
            if(i + 2 < nums.size()) nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
            else if(i + 1 < nums.size()) nums[i] = max(nums[i], nums[i + 1]);
        }
        
        return nums[0];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> robFirst(nums.begin(), nums.end() - 1);
        vector<int> robLast(nums.begin() + 1, nums.end());
        
        return max(robbingHouses(robFirst), robbingHouses(robLast));
    }
};
