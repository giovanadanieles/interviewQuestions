// Space complexity: O(N) - less than 27.77% of C++ online submissions
//  Time complexity: O(N) - faster than 41.21% of C++ online submissions
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0, prefixNeeded;
        unordered_map<int, int> prefixSumCount;
        
        prefixSumCount[0]++;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            prefixNeeded = sum - k;
            
            if(prefixSumCount[prefixNeeded] != 0) ans += prefixSumCount[prefixNeeded];
            
            prefixSumCount[sum]++;
        }
        
        return ans;
    }
};
