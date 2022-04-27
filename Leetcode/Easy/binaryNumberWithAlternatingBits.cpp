// Space complexity: O(1) - 5.9 MB, less than 67.62% of C++ online submissions
//  Time complexity: O(log N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int firstBit, secBit;
        bool ans = true;
        
        while(n > 0){
            firstBit = n % 2;
            
            n >>= 1;
            secBit = n % 2;
                        
            ans &= (firstBit ^ secBit);
        }
        
        return ans;
    }
};
