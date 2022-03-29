// Space complexity: O(1) - 5.8 MB, less than 77.13% of C++ online submissions
//  Time complexity: O(log10 N) - 9 ms, faster than 6.05% of C++ online submissions
// class Solution {
// public:
//     int reverse(int x) {
//         int signal = 1, reversed = 0;
        
//         if(x == INT_MIN || x == INT_MAX) return 0;
        
//         if(x < 0){
//             signal = -1;
//             x *= -1;
//         }
        
//         while(x > 0){
//             if(reversed > (INT_MAX - x % 10) / 10) return 0;
            
//             reversed = reversed * 10 + x % 10;
            
//             x /= 10;
//         }
        
//         return reversed * signal;
//     }
// };



// Space complexity: O(1) - 5.8 MB, less than 77.13% of C++ online submissions
//  Time complexity: O(log10 N) - 3 ms, faster than 59.08% of C++ online submissions
class Solution {
public:
    int reverse(int x) {
        int pop, reversed = 0;
        
        while(x != 0){
            pop = x % 10;
            
            if(reversed > INT_MAX / 10 || (reversed == INT_MAX && pop > 7)) return 0;
            if(reversed < INT_MIN / 10 || (reversed == INT_MIN && pop < -8)) return 0;
            
            reversed = reversed * 10 + pop;
            
            x /= 10;
        }
        
        return reversed;
    }
};
