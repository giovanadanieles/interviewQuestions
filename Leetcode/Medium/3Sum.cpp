// Space complexity: O(1) - 294.5 MB, less than 5.25% of C++ online submissions
//  Time complexity: O(N ^ 2 log N) - 1860 ms, faster than 5.00% of C++ online submissions
// class Solution {
// public:
//     set<vector<int>> repAns;
    
//     void twoSum(vector<int>& nums, int left, int target){
//         int right = nums.size() - 1;
                
//         while(left < right){
//             if(nums[left] + nums[right] == target){
//                 repAns.insert({-target, nums[left], nums[right]});
//                 left++;
//             }
//             else if(nums[left] + nums[right] < target) left++;
//             else right--;
//         }
//     }
    
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int curPos = 0;
//         vector<vector<int>> ans;
        
//         sort(nums.begin(), nums.end());
        
//         while(curPos < nums.size()){  
//             twoSum(nums, curPos + 1, -nums[curPos]);
                        
//             curPos++;
//         }
        
//         for(auto it = repAns.begin(); it != repAns.end(); it++){
//             ans.push_back(*it);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - 22.1 MB, less than 35.17% of C++ online submissions
//  Time complexity: O(N ^ 2) - 80 ms, faster than 86.79% of C++ online submissions
class Solution {
public:
    vector<vector<int>> ans;
    
    void twoSum(vector<int>& nums, int left, int target){
        int right = nums.size() - 1;
                
        while(left < right){
            if(nums[left] + nums[right] == target){
                ans.push_back({-target, nums[left], nums[right]});
                left++;
                
                while(nums[left] == nums[left - 1] && left < right) left++;
            }
            else if(nums[left] + nums[right] < target) left++;
            else right--;
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int curPos = 0;
        
        sort(nums.begin(), nums.end());
        
        while(curPos < nums.size()){  
            if(curPos > 0 && nums[curPos] == nums[curPos - 1]){
                curPos++;
                continue;
            }
            
            twoSum(nums, curPos + 1, -nums[curPos]);
                        
            curPos++;
        }
        
        return ans;
    }
};
