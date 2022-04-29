// Space complexity: O(1) - 9.7 MB, less than 24.10% of C++ online submissions
//  Time complexity: O(logN) - 3 ms, faster than 91.55% of C++ online submissions
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left, right, middle;
        
        left = 0, right = nums.size() - 1;
        
        while(left <= right){
            middle = left + ((right - left) >> 1);
            
            if(nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        
        return left;
    }
};
