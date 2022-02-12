// Space complexity: O(N) - less than 5.39% of C++ online submissions
//  Time complexity: O(N) - faster than 41.88% of C++ online submissions
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         unordered_map<int, vector<int>> numbers;
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             numbers[nums[i]].push_back(i);    
//         }
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             if(target - nums[i] == nums[i]){
//                 if(numbers[target - nums[i]].size() >= 2){
//                     ans.push_back(numbers[target - nums[i]][0]);
//                     ans.push_back(numbers[target - nums[i]][1]);
                    
//                     break;
//                 }
//             }
//             else{
//                 if(numbers[target - nums[i]].size() >= 1){
//                     ans.push_back(i);
//                     ans.push_back(numbers[target - nums[i]][0]);
//                     break;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N) - less than 51.45% of C++ online submissions
//  Time complexity: O(N) - faster than 68.65% of C++ online submissions
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> numbers;
        
        for(unsigned int i = 0; i < nums.size(); i++){
            if(numbers.find(target - nums[i]) != numbers.end()){
                ans.push_back(i);
                ans.push_back(numbers[target - nums[i]]);
                break;
            }
            else numbers[nums[i]] = i;
        }
        
        return ans;
    }
};
