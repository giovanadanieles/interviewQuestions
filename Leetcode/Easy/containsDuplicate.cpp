// Space complexity: O(1) - less than 66.37% of C++ online submissions
//  Time complexity: O(NlogN) - faster than 77.29% of C++ online submissions
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         for(unsigned int i = 0; i < nums.size() - 1; i++){            
//             if(nums[i] == nums[i + 1]) return true;
//         }
        
//         return false;
//     }
// };



// Space complexity: O(N) - less than 21.99% of C++ online submissions
//  Time complexity: O(1) - faster than 31.24% of C++ online submissions
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> values;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            values.insert(nums[i]);
        }
        
        return values.size() != nums.size();
    }
};
