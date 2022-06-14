// Space complexity: O(N) - 127.2 MB, less than 23.93% of C++ online submissions
//  Time complexity: O(N) - 460 ms, faster than 62.58% of C++ online submissions
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int globalMax = 0, localMax, left, right;
        unordered_set<int> usedValues;
        
        localMax = nums[0], left = 0;
        usedValues.insert(nums[left]);
        
        for(right = 1; right < nums.size(); right++){
            if(usedValues.find(nums[right]) != usedValues.end()){
                globalMax = max(globalMax, localMax);
                
                while(usedValues.find(nums[right]) != usedValues.end()){
                    usedValues.erase(nums[left]);
                    localMax -= nums[left];
                    
                    left++;
                }
            }
            
            usedValues.insert(nums[right]);
            localMax += nums[right];
        }
        
        
        return max(globalMax, localMax);
    }
};
