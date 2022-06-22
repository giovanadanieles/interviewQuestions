// Ref: https://www.youtube.com/watch?v=8g78yfzMlao
// Space complexity: O(1) - 83 MB, less than 40.77% of C++ online submissions
//  Time complexity: O(N) - 177 ms, faster than 88.31% of C++ online submissions
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int index;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) nums[i] = 0;    
        }
        
        for(auto num : nums){
            index = abs(num) - 1;
            
            if(index >= 0 && index < nums.size()){
                if(nums[index] > 0) nums[index] *= -1;
                else if(nums[index] == 0) nums[index] = -(int)nums.size();
            }
        }
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0) return i + 1;
        }
        
        return nums.size() + 1;
    }
};
