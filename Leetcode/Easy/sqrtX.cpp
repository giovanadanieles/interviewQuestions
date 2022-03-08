// Space complexity: O(1) - less than 75.05% of C++ online submissions
//  Time complexity: O(sqrt(N)) = O(N) - faster than 14.55 % of C++ online submissions
// class Solution {
// public:
//     int mySqrt(int x) {
//         unsigned int i;
        
//         if(x == 0) return 0;
        
//         for(i = 2; i * i <= x; i++){
//             if(i * i == x) return i;
//             else if(i * i > x) return i - 1;
//         }
        
//         return i - 1;
//     }
// };



// Space complexity: O(1) - less than 75.05% of C++ online submissions
//  Time complexity: O(log N) - faster than 67.45% of C++ online submissions
class Solution {
public:
    int mySqrt(int x) {
        int middle, left, right;
        
        left = 1, right = x;
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(middle > x / middle) right = middle - 1;
            else if(middle < x / middle) left = middle + 1;
            else return middle;
        }
        
        return right;
    }
};
