// Space complexity: O(1) - 5.8 MB, less than 72.14% of C++ online submissions
//  Time complexity: O(logN) - 8 ms, faster than 44.30% of C++ online submissions
// class Solution {
// public:
//     int arrangeCoins(int n) {
//        long long left, right, middle;
        
//         left = 0, right = n;
//         while(left <= right){
//             middle = left + (right - left) / 2;
            
//             if(middle * middle + middle == 2ll * n) return middle;
//             else if(middle * middle + middle < 2ll * n) left = middle + 1;
//             else right = middle - 1;
//         }
        
//         return right;
//     }
// };



// COMPLETING THE SQUARE TECHNIQUE
// Space complexity: O(1) - 6 MB, less than 28.85% of C++ online submissions
//  Time complexity: O(logN) - 3 ms, faster than 79.18% of C++ online submissions
class Solution {
public:
    int arrangeCoins(int n) {
        /*
        *   k(k + 1) <= 2N
        *   (k + 1/2)^2 - 1/4 <= 2N
        *   k = sqrt(2N + 1/4) - 1/2
        */
        
       return (int)(sqrt(2ll * n + 0.25) - 0.5);
    }
};
