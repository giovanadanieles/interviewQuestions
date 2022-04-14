// Space complexity: O(1) - 5.8 MB, less than 77.98% of C++ online submissions
//  Time complexity: O(N) - 3 ms, faster than 28.81% of C++ online submissions
class Solution {
public:
    int xorOperation(int n, int start) {
        int xored = start, digit;
        
        for(int i = 1; i < n; i++){
            digit = start + 2 * i;
            
            xored ^= digit;
        }
        
        return xored;
    }
};
