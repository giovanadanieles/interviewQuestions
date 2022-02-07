// Space complexity: O(N) - less than 20.36% of C++ online submissions
//  Time complexity: O(max(num1.size(), num2.size())) == O(N) - faster than 53.23% of C++ online submissions
class Solution {
public:
    string addStrings(string num1, string num2) {
        int curIndex = 0, carry = 0, n1, n2;
        string ans = "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        while(curIndex < num1.size() || curIndex < num2.size() || carry > 0){
            n1 = 0;
            if(curIndex < num1.size()) n1 = num1[curIndex] - '0';
            
            n2 = 0;
            if(curIndex < num2.size()) n2 = num2[curIndex] - '0';
            
            ans = to_string((n1 + n2 + carry) % 10) + ans;
            carry = (n1 + n2 + carry) / 10;
            
            curIndex++;
        }
        
        return ans;
    }
};
