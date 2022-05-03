// Space complexity: O(1) - 5.9 MB, less than 71.89% of C++ online submissions
//  Time complexity: O(1) - 3 ms, faster than 52.02% of C++ online submissions
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n < 1) return false;
        
//         while(n > 1){
//             if(n % 4 != 0) return false;
//             n /= 4;
//         }
        
//         return true;
//     }
// };



// Ref: https://leetcode.com/problems/power-of-four/discuss/80457/Java-1-line-(cheating-for-the-purpose-of-not-using-loops)
// Space complexity: O(1) - 5.9 MB, less than 26.25% of C++ online submissions
//  Time complexity: O(1) - 4 ms, faster than 38.01% of C++ online submissions
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 0x55555555 is a hexametrical number，it is 1010101010101010101010101010101
        return (n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0);
    }
};
