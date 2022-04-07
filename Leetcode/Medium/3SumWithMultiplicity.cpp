// Ref: https://leetcode.com/problems/3sum-with-multiplicity/discuss/1918457/C%2B%2B-Simplest-Solution-or-W-Easy-Explanation-or-Intuitive

// Space complexity: O(N ^ 2) - 10.9 MB, less than 20.27% of C++ online submissions
//  Time complexity: O(N ^ 2) - 1149 ms, faster than 24.75% of C++ online submissions
class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size(), mod = 1e9+7, ans = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) {
            ans = (ans + m[target - nums[i]]) % mod;
            
            for(int j=0; j<i; j++) m[nums[i] + nums[j]]++;
        }
        
        return ans;   
    }
};
