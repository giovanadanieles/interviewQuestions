// Space complexity: O(1) - 8.4 MB, less than 25.51% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         vector<int> colorFreq(3, 0);
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             colorFreq[nums[i]]++;
//         }
        
//         for(unsigned int i = 0, index = 0; i < colorFreq.size(); i++){
//             for(unsigned int j = 0; j < colorFreq[i]; j++, index++){
//                 nums[index] = i;
//             }
//         }
//     }
// };



// DUTCH PARTITIONING PROBLEM
// Space complexity: O(1) - 8.3 MB, less than 70.60% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = -1, two = nums.size() - 1;
        
        for(int i = 0; i <= two; i++){
            if(nums[i] == 0){
                if(one != -1) swap(nums[i], nums[one]), one++;
            }
            else if(nums[i] == 1){
                if(one == -1) one = i;
            }
            else{
                swap(nums[i], nums[two]);
                two--, i--;
            }
        }
    }
};
