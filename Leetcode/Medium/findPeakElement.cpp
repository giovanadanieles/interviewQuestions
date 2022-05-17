// Space complexity: O(1) - 8.8 MB, less than 50.98% of C++ online submissions
//  Time complexity: O(logN) - 7 ms, faster than 40.82% of C++ online submissions
class Solution {
public:
    
    /*
        Binary search works here because we need to return any local peak, not necessarily the global peak.
        Therefore, say we take the middle value. If the number to its left is smaller than it, then if the number
    to its right is also smaller than it, the middle value is a local     peak. If the number to its right is 
    higher than the middle value, then somewhere on the right there must be a peak - either the numbers ascend 
    and then descend, in which case there would be a peak where the change from ascent to descent happens, or 
    the numbers continue to ascend until the end of the array, in which case the last value in the array would 
    be a local peak.
        The same with the other way. If the value on the left on the middle value is bigger than the middle value, 
    then it must be that either the middle value itself is a peak or that there is definitely a peak on the left 
    side of the middle value. This is because if the number on the left is bigger than the middle value, there 
    are two options: either the numbers continue ascending in the left direction until the end, in which case the 
    first value of the array would be a peak, or the values increase to the left until a point at which they start
    decreasing, and that point would be a peak.
    */
    
    int findPeakElement(vector<int>& nums) {
        int left, right, middle;
                
        left = 0, right = nums.size() - 1;
        while(left < right){
            middle = left + (right - left) / 2;
            
            if(nums[middle] > nums[middle + 1]) right = middle;
            else left = middle + 1;
        }
        
        return left;
    }
};

// Ref: https://leetcode.com/problems/find-peak-element/solution/
