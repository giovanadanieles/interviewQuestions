// Space complexity: O(1), from sorting - 58.2 MB, less than 62.91% of C++ online submissions
//  Time complexity: O(NlogN) - 143 ms, faster than 86.92% of C++ online submissions
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left, right, ans = 0;
        
        sort(nums.begin(), nums.end());
        
        left = 0, right = nums.size() - 1;
        
        while(left < right){
            if(nums[left] + nums[right] == k) ans++, left++, right--;
            else if(nums[left] + nums[right] < k) left++;
            else right--;
        }
        
        return ans;
    }
};
