// Space complexity: O(1) - 10.2 MB, less than 23.39% of C++ online submissions
//  Time complexity: O(log N) - 11 ms, faster than 9.79% of C++ online submissions
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int left, right, middle;
        
//         left = 0, right = nums.size() - 1;
//         while(left < right){
//             middle = left + (right - left) / 2;

//             if(nums[middle] > nums[0] || nums[middle] > nums[right]) left = middle + 1;
//             else right = middle;
//         }
                
//         return min(nums[0], nums[left]);
//     }
// };



// Space complexity: O(1) - 10.1 MB, less than 72.23% of C++ online submissions
//  Time complexity: O(log N) - 3 ms, faster than 80.09% of C++ online submissions
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left, right, middle;
                
        left = 0, right = nums.size() - 1;
        
        if(nums.size() == 1 || nums[right] > nums[0]) return nums[0];
        
        while(left <= right){
            middle = left + (right - left) / 2;

            if(nums[middle] > nums[middle + 1]) return nums[middle + 1];
            if(nums[middle] < nums[middle - 1]) return nums[middle];
            
            if(nums[middle] > nums[0]) left = middle + 1;
            else right = middle - 1;
        }
                
        return -1;
    }
};
