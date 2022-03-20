// Space complexity: O(1) - 96 ms, faster than 90.33% of C++ online submissions
//  Time complexity: O(N) - 83.5 MB, less than 7.28% of C++ online submissions
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // keeping track of 5 and 10 dollar bills
        int fives = 0, tens = 0;
        
        for(unsigned int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) fives++;
            else if(bills[i] == 10) tens++, fives--;
            else if(tens > 0) tens--, fives --; 
            else fives -= 3;
            
            if(fives < 0) return false;
        }
        
        return true;
    }
};
