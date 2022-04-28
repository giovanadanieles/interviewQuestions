// Space complexity: O(1) - 8.9 MB, less than 36.90% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 44.12% of C++ online submissions
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                
                left++;
            }
        }
    
        return left;
    }
};
