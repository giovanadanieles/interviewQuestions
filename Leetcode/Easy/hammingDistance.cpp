// Space complexity: O(1) - 6 MB, less than 27.46% of C++ online submissions
//  Time complexity: O(log N) - 3 ms, faster than 28.91% of C++ online submissions
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int x_, y_, ans = 0;
        
//         while(x != 0 || y != 0){
//             x_ = 0;
//             if(x != 0) x_ = x % 2;
            
//             y_ = 0;
//             if(y != 0) y_ = y % 2;
            
//             ans += x_ ^ y_;
            
//             x /= 2, y /= 2;
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - 5.9 MB, less than 27.46% of C++ online submissions
//  Time complexity: O(log N) - 3 ms, faster than 28.91% of C++ online submissions
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        
        x = x ^ y;
        
        // counting 1s
        while(x > 0){
            ans += x & 1;
            x >>= 1;
        }
        
        return ans;
    }
};
