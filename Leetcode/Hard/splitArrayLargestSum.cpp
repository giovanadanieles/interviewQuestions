// Ref: https://www.youtube.com/watch?v=OmJuyKaGGjs

// Space complexity: O(1) - 7.1 MB, less than 74.76% of C++ online submissions
//  Time complexity: O(N * log(S)), being S sum of integers in the array - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isPossibleSplit(vector<int>& nums, int m, int sum){
       int splits = 0, curSum = 0; 
        
        for(unsigned int i = 0; i < nums.size(); i++){
            curSum += nums[i];
            
            if(curSum > sum){
                splits++;
                curSum = nums[i];
                
                if(splits > m - 1) return false;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int left = INT_MIN, right = 0, middle, ans;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            left = max(left, nums[i]);
            right += nums[i];
        }
        
        while(left < right){
            middle = left + (right - left) / 2;
            
            if(isPossibleSplit(nums, m, middle) == true){
                right = middle;
            }
            else left = middle + 1;
        }
        
        return left;
    }
};
