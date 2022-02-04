// Space complexity: O(1) - less than 29.67% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    string addBinary(string a, string b) {
        int x, y, aSize, bSize, curPos = 0, carry = 0;
        string ans = "";
        
        aSize = a.size();
        bSize = b.size();
        
        while(curPos < aSize || curPos < bSize || carry != 0){
            x = 0;
            if(curPos < aSize && a[aSize - curPos - 1] == '1') x = 1;
            
            y = 0;
            if(curPos < bSize && b[bSize - curPos - 1] == '1') y = 1;
            
            ans = to_string((x + y + carry) % 2) + ans;
            carry = (x + y + carry) / 2;
            
            curPos++;
        }
        
        return ans;
    }
};
