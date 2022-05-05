// Space complexity: O(1) - 13.7 MB, less than 65.62% of C++ online submissions
//  Time complexity: O(logN) - 8 ms, faster than 78.24% of C++ online submissions
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right, middle, lower = -1, upper = -1;
        
        left = 0, right = nums.size() - 1;
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(nums[middle] == target) lower = middle;
            
            if(nums[middle] >= target) right = middle - 1;
            else left = middle + 1;
        }
        
        if(lower == -1) return {lower, upper};
        
        left = 0, right = nums.size() - 1;
        while(left <= right){
            middle = left + (right - left) / 2;

            if(nums[middle] == target) upper = middle;

            if(nums[middle] <= target) left = middle + 1;
            else right = middle - 1;
        }
        
        return {lower, upper};
    }
};
