// Ref: https://www.geeksforgeeks.org/maximum-product-subarray/

// KADANE'S ALGORITHM
// Space complexity: O(1) - 13.8 MB, less than 26.55% of C++ online submissions
//  Time complexity: O(N) - 10 ms, faster than 52.90% of C++ online submissions
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int aux, minCurrent, maxCurrent, maxGlobal;
        
//         minCurrent = maxCurrent = maxGlobal = nums[0];
        
//         for(unsigned int i = 1; i < nums.size(); i++){
//             aux = max({nums[i], maxCurrent * nums[i], minCurrent * nums[i]});
            
//             minCurrent = min({nums[i], maxCurrent * nums[i], minCurrent * nums[i]});
//             maxCurrent = aux;
            
//             if(maxCurrent > maxGlobal) maxGlobal = maxCurrent;
//         }
        
//         return maxGlobal;
//     }
// };



// KADANE'S ALGORITHM
// Space complexity: O(1) - 13.9 MB, less than 26.55% of C++ online submissions
//  Time complexity: O(N) - 8 ms, faster than 69.64% of C++ online submissions
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minCurrent, maxCurrent, maxGlobal;
        
        minCurrent = maxCurrent = maxGlobal = nums[0];
        
        for(unsigned int i = 1; i < nums.size(); i++){            
            if(nums[i] < 0) swap(minCurrent, maxCurrent);
            
            minCurrent = min(nums[i], minCurrent * nums[i]);
            maxCurrent = max(nums[i], maxCurrent * nums[i]);
            
            if(maxCurrent > maxGlobal) maxGlobal = maxCurrent;
        }
        
        return maxGlobal;
    }
};
