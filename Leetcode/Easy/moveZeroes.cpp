// Space complexity: O(1) - 19.3 MB, less than 14.06% of C++ online submissions
//  Time complexity: O(N) - 31 ms, faster than 60.03% of C++ online submissions
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         unsigned int left, right;
        
//         for(left = 0, right = 0; right < nums.size(); left++, right++){
//             while(right + 1 < nums.size() && nums[right] == 0){
//                 right++;
//             }
            
//             nums[left] = nums[right];
//         }
        
//         for(; left < right; left++) nums[left] = 0;
//     }
// };



// Space complexity: O(1) - 19.3 MB, less than 58.42% of C++ online submissions
//  Time complexity: O(N) - 27 ms, faster than 71.43% of C++ online submissions
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unsigned int left, right;
        
        for(left = 0, right = 0; left < nums.size(); left++){
           if(nums[left] != 0){
               swap(nums[right], nums[left]);
               right++;
           }
        }  
    }
};
