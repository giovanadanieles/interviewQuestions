// Space complexity: O(1) - 17.9 MB, less than 65.18% of C++ online submissions
//  Time complexity: O(N) - 30 ms, faster than 45.60% of C++ online submissions
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         /*
//             Arithmetic Progression: Sn = a1 + a2 + … + an  = [(a1 + an) * n] / 2 
//         */  
        
//         long long sum = 0, totalSum;
//         int min_ = INT_MAX, max_ = INT_MIN;
        
//         for(unsigned int i = 0; i < nums.size(); i++){
//             sum += nums[i];
            
//             min_ = min(min_, nums[i]);
//             max_ = max(max_, nums[i]);
//         }
                        
//         if(min_ != 0) return 0;
//         else if(max_ != nums.size()) return nums.size();
        
//         totalSum = (min_ + max_) * (nums.size() + 1) / 2;
                
//         return totalSum - sum;
//     }
// };



// Space complexity: O(1) - 18 MB, less than 65.18% of C++ online submissions
//  Time complexity: O(N) - 15 ms, faster than 94.40% of C++ online submissions
class Solution {
public:
    int missingNumber(vector<int>& nums) {               
        return (nums.size() * (nums.size() + 1) / 2) - accumulate(nums.begin(), nums.end(), 0);
    }
};
