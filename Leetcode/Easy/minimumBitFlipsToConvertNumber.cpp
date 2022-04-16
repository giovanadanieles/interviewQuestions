// Space complexity: O(1) - 6 MB, less than 36.33% of C++ online submissions
//  Time complexity: O(log N) - 4 ms, faster than 24.21% of C++ online submissions
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int numFlips = 0;
        
//         while(start > 0 || goal > 0){
//             numFlips += (start & 1) ^ (goal & 1);
            
//             start >>= 1, goal >>= 1;
//         }
        
//         return numFlips;
//     }
// };



// Space complexity: O(1) - 5.9 MB, less than 36.33% of C++ online submissions
//  Time complexity: O(log N) - 4 ms, faster than 24.21% of C++ online submissions
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int numFlips = 0;
        
        start ^= goal;
        
        while(start > 0){
            numFlips += start & 1;
            start >>= 1;
        }
        
        return numFlips;
    }
};
