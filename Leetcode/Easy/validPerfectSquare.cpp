// Space complexity: O(1) - 5.9 MB, less than 65.75% of C++ online submissions
//  Time complexity: O(logN) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num, middle;
        
        while(left <= right){
            middle = left + (right - left) / 2;
            
            if(middle * middle == num) return true;
            else if(middle * middle < num) left = middle + 1;
            else right = middle - 1;
        }
        
        return false;
    }
};
