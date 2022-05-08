// Ref: https://www.youtube.com/watch?v=q5ANAl8Z458

// Space complexity: O(N) - 37.1 MB, less than 99.17% of C++ online submissions
//  Time complexity: O(N) - 76 ms, faster than 84.34% of C++ online submissions
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int curMin = nums[0];
        stack<pair<int, int>> stck; // monotonic decreasing stack
        
        for(unsigned int i = 1; i < nums.size(); i++){
            while(!stck.empty() && nums[i] >= stck.top().first) stck.pop();
            if(!stck.empty() && nums[i] > stck.top().second) return true;
            
            stck.push({nums[i], curMin});
            curMin = min(curMin, nums[i]);
        }
        
        return false;
    }
};
