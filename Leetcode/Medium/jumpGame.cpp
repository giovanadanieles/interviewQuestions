// Space complexity: O(N) - 48.6 MB, less than 23.69% of C++ online submissions
//  Time complexity: O(N ^ 2) - 235 ms, faster than 21.77% of C++ online submissions 
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         vector<bool> isPossible(nums.size(), false);
        
//         isPossible[0] = true;
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             if(isPossible[i] == true){
//                 if(nums[i] > nums.size() - i) nums[i] = nums.size() - i;
                
//                 if(isPossible[nums.size() - 1] == true) return true;
                
//                 for(int j = nums[i]; j > 0; j--){
//                     isPossible[i + j] = true;
//                 }
//             }
//         }
        
//         return false;
//     }
// };



// Space complexity: O(1) - 48.3 MB, less than 91.94% of C++ online submissions
//  Time complexity: O(N) - 99 ms, faster than 46.68% of C++ online submissions
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left, right;
        
        left = nums.size() - 2, right = nums.size() - 1;
        
        while(left >= 0){
            if(left + nums[left] >= right) left--, right = left + 1;
            else left--;
        }
        
        return right == 0 ? true : false;
    }
};
