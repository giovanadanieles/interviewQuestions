// Space complexity: O(1) - 6 MB, less than 32.60% of C++ online submissions
//  Time complexity: O(log N) - 4 ms, faster than 18.92% of C++ online submissions
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        
        while(mask < n) mask = (mask << 1) | 1;
        
        return mask & ~n;
    }
};
