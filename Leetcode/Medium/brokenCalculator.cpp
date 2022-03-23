// Ref: https://www.youtube.com/watch?v=SB-wRo-dPvg

// Space complexity: O(1) - 6 MB, less than 30.21% of C++ online submissions
//  Time complexity: O(log target) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int operations = 0;
                
        while(startValue != target){
            if(startValue > target){
                operations += startValue - target;
                startValue = target;
            }
            else{
                if(target % 2 == 1) target++;
                else target /= 2;
                
                operations++;
            }
        }
        
        return operations;
    }
};
