// Ref 1: https://www.youtube.com/watch?v=gVUrDV4tZfY
// Ref 2: https://leetcode.com/problems/sum-of-two-integers/discuss/302977/C++:-the-evil-runtime-error:-left-shift-of-negative-value-reason-and-how-to-solve

// Space complexity: O(1) - 5.8 MB, less than 76.25% of C++ online submissions
//  Time complexity: O(N), being N max # of numbers in a and b -  0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int getSum(int a, int b) {
        // sum == combination of ^(xor) and &&
        unsigned int temp;
        
        while(b != 0){
            temp = a & b;
            temp <<= 1;
            
            a = a ^ b;
            b = temp;
        }
        
        return a;
    }
};
