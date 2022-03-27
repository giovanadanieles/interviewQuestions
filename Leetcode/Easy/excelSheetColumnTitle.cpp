// Space complexity: O(1) - 5.9 MB, less than 78.30% of C++ online submissions
//  Time complexity: O(log N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        
        while(columnNumber > 0){
            columnNumber--;
            
            ans += 'A' + columnNumber % 26;
            
            columnNumber /= 26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
