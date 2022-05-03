// Space complexity: O(N) - 30.9 MB, less than 26.94% of C++ online submissions
//  Time complexity: O(N) - 143 ms, faster than 7.39% of C++ online submissions
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         unordered_map<int, int> alreadyUsed;
//         int duplicated, missing;
        
//         for(int n : nums) alreadyUsed[n]++;
        
//         for(int i = 1; i <= nums.size(); i++){
//             if(alreadyUsed.find(i) != alreadyUsed.end()){
//                 if(alreadyUsed[i] == 2) duplicated = i;
//             }
//             else missing = i;
//         }
               
//         return {duplicated, missing};
//     }
// };



// Ref: https://leetcode.com/problems/set-mismatch/solution/ (approach 6)
// Space complexity: O(1) - 21.4 MB, less than 68.45% of C++ online submissions
//  Time complexity: O(N) - 30 ms, faster than 86.79% of C++ online submissions
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicated, missing = -1;
        
        for(int n : nums){
            if(nums[abs(n) - 1] < 0) duplicated = abs(n);
            else nums[abs(n) - 1] *= -1;
        }
        
        for(int i = 0; i < nums.size() && missing == -1; i++){
            if(nums[i] > 0) missing = i + 1;
        }
        
        return {duplicated, missing};
    }
};
