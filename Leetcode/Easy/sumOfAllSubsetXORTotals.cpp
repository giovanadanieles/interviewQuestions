// Space complexity: O(N) - 7.2 MB, less than 29.09% of C++ online submissions
//  Time complexity: O(2 ^ N) - 4 ms, faster than 66.49% of C++ online submissions
// class Solution {
// public:
//     vector<int> path;
    
//     void backtracking(vector<int> &nums, int curPos, int &sum){
//         if(curPos >= nums.size()){
//             if(path.size() > 0){
//                 int xored = path[0];

//                 for(unsigned int i = 1; i < path.size(); i++) xored ^= path[i];

//                 sum += xored;
//             }
            
//             return;
//         }
        
//         path.push_back(nums[curPos]);
//         backtracking(nums, curPos + 1, sum);
        
//         path.pop_back();
//         backtracking(nums, curPos + 1, sum);
//     }
    
//     int subsetXORSum(vector<int>& nums) {
//         int sum = 0;
        
//         backtracking(nums, 0, sum);
        
//         return sum;
//     }
// };



// Space complexity: O(H) - 7.1 MB, less than 55.83% of C++ online submissions
//  Time complexity: O(2 ^ N) - 2 ms, faster than 79.21% of C++ online submissions
class Solution {
public:    
    void backtracking(vector<int> &nums, int xored, int curPos, int &sum){
        if(curPos >= nums.size()){
            sum += xored;
            return;
        }
        
        backtracking(nums, xored, curPos + 1, sum);
        
        xored ^= nums[curPos];
        backtracking(nums, xored, curPos + 1, sum);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        
        backtracking(nums, 0, 0, sum);
        
        return sum;
    }
};
