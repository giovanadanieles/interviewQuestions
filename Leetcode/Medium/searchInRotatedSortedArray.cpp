// Ref: https://www.youtube.com/watch?v=U8XENwh8Oy8

// Space complexity: O(1) - 11 MB, less than 95.86% of C++ online submissions
//  Time complexity: O(log n) - 6 ms, faster than 48.55% of C++ online submissions
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, middle;
        
        left = 0, right = nums.size() - 1;
        
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(nums[middle] == target) return middle;
            
            // middle is in the left portion of the array
            if(nums[left] <= nums[middle]){
                if(target > nums[middle] || target < nums[left]) left = middle + 1;
                else right = middle - 1;
            }
            // middle is in the right portion of the array
            else{
                if(target < nums[middle] || target > nums[right]) right = middle - 1;
                else left = middle + 1;
            }
        }
        
        return -1;
    }
};
