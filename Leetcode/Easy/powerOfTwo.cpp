// Space complexity: O(1) - 5.8 MB, less than 70.61% of C++ online submissions
//  Time complexity: O(logN) - 2 ms, faster than 54.71% of C++ online submissions
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {  
//         if(n < 1) return false;
        
//         while(n > 1){
//             if(n % 2 != 0) return false;
            
//             n /= 2;
//         }
        
//         return true;
//     }
// };



// Space complexity: O(1) - 6 MB, less than 25.66% of C++ online submissions
//  Time complexity: O(numberOfBits) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {  
//        if(n < 1) return false;
        
//         if(__builtin_popcount(n) == 1) return true;
//         else return false;
//     }
// };



// Ref: https://leetcode.com/problems/power-of-two/discuss/1638707/PythonC%2B%2BJava-Detailly-Explain-Why-n-and-n-1-Works-oror-1-Line-oror-100-Faster-oror-Easy
// Space complexity: O(1) - 5.8 MB, less than 70.61% of C++ online submissions
//  Time complexity: O(1) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isPowerOfTwo(int n) {  
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
