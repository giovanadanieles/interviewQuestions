// Space complexity: O(N) - 77.1 MB, less than 67.64% of C++ online submissions
//  Time complexity: O(N) - 217 ms, faster than 66.31% of C++ online submissions
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastAppearence;

        if(nums.size() == 1) return false;

        for(unsigned int i = 0; i < nums.size(); i++){
            if(lastAppearence.find(nums[i]) == lastAppearence.end()) lastAppearence[nums[i]] = i;
            else{
                if(i - lastAppearence[nums[i]] <= k) return true;
                else lastAppearence[nums[i]] = i;
            }
        }

        return false;
    }
};
