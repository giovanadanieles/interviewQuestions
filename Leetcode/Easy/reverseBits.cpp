// Space complexity: O(1) - less than 51.31% of C++ online submissions 
//  Time complexity: O(1) - faster than 18.24% of C++ online submissions
// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t reverse = 0, bit;
        
//         for(int i = 0; i < 32; i++){
//             // getting the ith bit
//             bit = n % 2;
//             reverse = reverse * 2 + bit;
            
//             n /= 2;
//         }
        
//         return reverse;
//     }
// };



// Space complexity: O(1) - less than 51.04% of C++ online submissions
//  Time complexity: O(1) - faster than 100.00% of C++ online submissions
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, bit;
        
        for(int i = 0; i < 32; i++){
            bit = 1 & (n >> i);
            res |= bit << (31 - i); 
        }
        
        return res;
    }
};
