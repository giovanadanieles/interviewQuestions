// Space complexity: O(N) - 17.1 MB, less than 7.27% of C++ online submissions
//  Time complexity: O(N) - 15 ms, faster than 48.12% of C++ online submissions
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums){
//         vector<int> ans;
//         deque<int> sortedArray;
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             if(nums[i] % 2 == 0) sortedArray.push_front(nums[i]);
//             else sortedArray.push_back(nums[i]);
//         }
        
//         while(!sortedArray.empty()){
//             ans.push_back(sortedArray.front());
//             sortedArray.pop_front();
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - 16.2 MB, less than 57.32% of C++ online submissions
//  Time complexity: O(N) - 22 ms, faster than 18.67% of C++ online submissions
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        int left, right;
        
        left = 0, right = nums.size() - 1;
        while(left < right){
            if(nums[left] % 2 == 0 && nums[right] % 2 == 0) left++; 
            else if(nums[left] % 2 == 1 && nums[right] % 2 == 0){
                swap(nums[left], nums[right]);
                left++, right--;
            }
            else if(nums[left] % 2 == 0 && nums[right] % 2 == 1) left++, right--;
            else right--;
        }
        
        return nums;
    }
};
