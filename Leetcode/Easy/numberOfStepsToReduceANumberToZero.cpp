// Space complexity: O(1) - 5.9 MB, less than 25.12% of C++ online submissions
//  Time complexity: O(log N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int numberOfSteps(int num) {
        int numOfSteps = 0;
        
        while(num > 0){
            if(num % 2 == 0) num /= 2;
            else num--;
            
            numOfSteps++;
        }
        
        return numOfSteps;
    }
};
