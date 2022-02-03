// Space complexity: O(1) - less than 66.37% of C++ online submissions
//  Time complexity: O(NlogN) - faster than 77.29% of C++ online submissions
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(unsigned int i = 0; i < nums.size() - 1; i++){            
            if(nums[i] == nums[i + 1]) return true;
        }
        
        return false;
    }
};
