// Space complexity: O(N) - 25.6 MB, less than 24.81% of C++ online submissions
//  Time complexity: O(N) - 42 ms, faster than 46.11% of C++ online submissions
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int position;
//         vector<int> aux(nums.size());
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             position = (i + k) % nums.size();
//             aux[position] = nums[i];
//         }
        
//         nums = aux;
        
//         return;
//     }
// };



// Ref: https://www.youtube.com/watch?v=BHr381Guz3Y
// Space complexity: O(1) - 25 MB, less than 81.64% of C++ online submissions
//  Time complexity: O(N) - 42 ms, faster than 46.11% of C++ online submissions
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int left, right, rotations;
        
        left = 0, right = (int)nums.size() - 1;
        while(left < right) swap(nums[left++], nums[right--]);
        
        left = 0, right = k % (int)nums.size() - 1;
        while(left < right) swap(nums[left++], nums[right--]);
        
        left = k % nums.size(), right = (int)nums.size() - 1;
        while(left < right) swap(nums[left++], nums[right--]);
    }
};
