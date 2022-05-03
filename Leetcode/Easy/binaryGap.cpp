// Space complexity: O(1) - 5.8 MB, less than 79.26% of C++ online submissions
//  Time complexity: O(log N) or O(1) - 3 ms, faster than 33.15% of C++ online submissions
class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0, curGap = INT_MIN;
        
        while(n > 0){
            if(n & 1 == 1){
                maxGap = max(maxGap, curGap);
                curGap = 0;
            } 
            
            curGap++;   
            n >>= 1;
        }
        
        return maxGap;
    }
};
