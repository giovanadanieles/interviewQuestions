// Space complexity: O(N) - 7.3 MB, less than 60.22% of C++ online submissions
//  Time complexity: O(N) - 2 ms, faster than 55.81% of C++ online submissions
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodPairs = 0;
        unordered_map<int, int> pairs;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(pairs[nums[i]] != 0) goodPairs += pairs[nums[i]];
            
            pairs[nums[i]]++;
        }
        
        return goodPairs;
    }
};
