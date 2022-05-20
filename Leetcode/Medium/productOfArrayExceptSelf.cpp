// Ref: https://www.youtube.com/watch?v=bNvIQI2wAjk

// Space complexity: O(1) - 23.9 MB, less than 93.05% of C++ online submissions
//  Time complexity: O(N) - 35 ms, faster than 45.90% of C++ online submissions
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            original = [1,2,3,4]
            prefix   = [1,2,6,24]
            postfix = [24,24,12,4]
            
            original_0 = postfix[0]
            original_1 = prefix[0] * postfix[2]
            original_2 = prefix[1] * postfix[3]
            original_3 = prefix[2]
        */
        
        int prefix = 1, postfix = 1;
        vector<int> output(nums.size(), 1);
        
        // treating prefixes
        for(int i = 0; i < (int)nums.size(); i++){
            output[i] = prefix;
            prefix *= nums[i];
        }
        
        // treating postfixes
        for(int i = (int)nums.size() - 1; i >= 0; i--){
            output[i] *= postfix;
            postfix *= nums[i];
        }
       
        return output;
    }
};
