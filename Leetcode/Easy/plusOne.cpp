// Space complexity: O(1) - less than 13.34% of C++ online submissions
//  Time complexity: O(N) - faster than 47.07% of C++ online submissions
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int oldValue, carry = 0;
        
        digits[digits.size() - 1]++;
        
        for(int i = digits.size() - 1; i >= 0; i--){
            oldValue = digits[i];
            
            digits[i] = (carry + digits[i]) % 10;
            carry = (carry + oldValue) / 10;     
        }
        
        if(carry) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};
