// Space complexity: O(1) - 27.6 MB, less than 63.81% of C++ online submissions
//  Time complexity: O(log N) - 27.6 MB, less than 63.81% of C++ online submissions
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, middle;
        
        left = 0, right = nums.size() - 1;
        
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(nums[middle] == target) return middle;
            
            if(nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        
        return -1;
    }
};
