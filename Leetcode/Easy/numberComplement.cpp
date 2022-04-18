// Space complexity: O(1) - 5.9 MB, less than 42.42% of C++ online submissions
//  Time complexity: O(1) - 3 ms, faster than 31.10% of C++ online submissions
class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        
        while (mask < num) mask = (mask << 1) | 1;
        
        return ~num & mask;
    }
};
