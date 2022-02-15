// Space complexity: O(1) - less than 99.00% of C++ online submissions
//  Time complexity: O(N) - faster than 40.69% of C++ online submissions
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // X ^ 0 is always X
        // 0 ^ 0 is always 0
        // 1 ^ 1 is always 0
        int ans = 0;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        
        return ans;
    }
};
