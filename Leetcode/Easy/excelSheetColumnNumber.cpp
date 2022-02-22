// Space complexity: O(1) - less than 67.28% of C++ online submissions
//  Time complexity: O(N) - faster than 16.24% of C++ online submissions

class Solution {
public:
    typedef long long int lli;
    
    int titleToNumber(string columnTitle) {
        lli ans = 0;
        
        for(unsigned int i = 0; i < columnTitle.size(); i++){
            ans = ans * 26 + columnTitle[i] - 'A' + 1;
        }
        
        return ans;
    }
};
