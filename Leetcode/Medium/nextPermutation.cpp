// Ref: https://www.youtube.com/watch?v=quAS1iydq7U

// Space complexity: O(1) - 12.1 MB, less than 37.25% of C++ online submissions
//  Time complexity: O(N) - 7 ms, faster than 51.84% of C++ online submissions
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left, right;
        
        // finding first outside the maximum decreasing subarray
        left = nums.size() - 2;
        while(left >= 0){
            if(nums[left] < nums[left + 1]) break;
            
            left--;
        }
        
        if(left >= 0){
            // find first el of decreasing subarray greater than the outside value and swaping
            right = nums.size() - 1;
            while(left < right){
                if(nums[right] > nums[left]){
                    swap(nums[right], nums[left]);
                    break;
                }
                
                right--;
            }
            
            left++;
        }
        else left = 0;
        
        // transforming the decreasing subarray into an increasing subarray
        right = nums.size() - 1;
        while(left < right){
            swap(nums[left], nums[right]);
            
            left++, right--;
        }
    }
};
