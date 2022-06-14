// Ref: https://www.youtube.com/watch?v=3p2fBvxrVQA
// Space complexity: O(1) - 98.6 MB, less than 56.58% of C++ online submissions
//  Time complexity: O(N) - 226 ms, faster than 76.18% of C++ online submissions
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target, left = 0, right, sum = 0, ans = -1;
        
        target = -x;
        for(auto num : nums) target += num;
        
        if(target == 0) return nums.size();
        else if(target < 0) return ans;
            
        for(right = 0; right < nums.size(); right++){
            sum += nums[right];
            
            while(sum > target) sum -= nums[left++];
            
            if(sum == target) ans = max(ans, right - left + 1);
        }
        
        return ans == -1 ? -1 : nums.size() - ans;
    }
};
