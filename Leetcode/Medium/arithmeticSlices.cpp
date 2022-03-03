// Space complexity: O(N) - less than 16.40% of C++ online submissions
//  Time complexity: O(N) - faster than 49.33% of C++ online submissions
// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int ans = 0, seq = 1;
//         vector<int> dp;
        
//         /*
//             123468
//              11122
//               1334
//         */
        
//         dp.push_back(0);
        
//         for(unsigned int i = 1; i < nums.size(); i++){
//             dp.push_back(nums[i] - nums[i - 1]);
//         }
        
//         for(unsigned int i = 1; i < nums.size() - 1; i++){
//             if(dp[i] == dp[i + 1]){
//                 ans += seq;
//                 seq++;
//             }
//             else{
//                 seq = 1;
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - less than 55.35% of C++ online submissions
//  Time complexity: O(N) - faster than 49.33% of C++ online submissions
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int prev, cur, ans = 0, seq = 1;
        
        for(unsigned int i = 1; i < nums.size() - 1; i++){
            prev = nums[i] - nums[i - 1];
            cur = nums[i + 1] - nums[i];
            
            if(prev == cur){
                ans += seq;
                seq++;
            }
            else{
                seq = 1;
            }
        }
        
        return ans;
    }
};
