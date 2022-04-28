/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */



// Space complexity: O(1) - 6 MB, less than 23.42% of C++ online submissions
//  Time complexity: O(log N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     int guessNumber(int n) {
//         int res, left, right, middle;
        
//         left = 1, right = n;
//         while(left <= right){
//             middle = left + (right - left) / 2;
            
//             res = guess(middle);
            
//             if(res == 0) return middle;
//             else if(res == -1) right = middle - 1;
//             else left = middle + 1;
//         }
        
//         return -1;
//     }
// };



// Space complexity: O(1) - 6 MB, less than 23.42% of C++ online submissions
//  Time complexity: O(log N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int guessNumber(int n) {
        int left, right, middle;
        
        left = 1, right = n;
        while(left < right){
            middle = left + ((right - left) >> 1);
            
            if(guess(middle) <= 0) right = middle;
            else left = middle + 1;
        }
        
        return left;
    }
};
