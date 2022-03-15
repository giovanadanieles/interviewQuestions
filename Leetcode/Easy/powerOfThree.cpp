// Space complexity: O(1) -        6 MB, less than 30.25% of C++ online submissions
//  Time complexity: O(log3 N) -  32 ms, faster than 45.82% of C++ online submissions
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n <= 0) return false;
        
//         while(n > 1){
//             if(n % 3 != 0) return false;
//             n /= 3;
//         }
        
//         return true;
//     }
// };



// Space complexity: O(1) -  27 ms, less than 73.90% of C++ online submissions
//  Time complexity: O(1) - 5.9 MB, faster than 60.17% of C++ online submissions
class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
            Any integer number other than power of 3 which divides highest power of 3 value that integer can 
            hold (3^19 = 1162261467) will give reminder non-zero.
        */
        
        if(n > 0 && 1162261467 % n == 0) return true;
        else return false;
    }
};
