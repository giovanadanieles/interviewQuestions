// Ref: https://www.youtube.com/watch?v=a-62yK1S1O4
// Space complexity: O(denominator) - 6.2 MB, less than 95.73% of C++ online submissions
//  Time complexity: O(denominator) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    typedef long long int lli;
    
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        lli dividend, divisor, remainder_;
        unordered_map<lli, int> remainderToPos;
        
        if(numerator == 0) return "0";
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) ans += "-";
        
        dividend = abs((lli)numerator);
        divisor = abs((lli)denominator);
        remainder_ = dividend % divisor;
        
        ans += to_string(dividend / divisor);
        
        if(remainder_ == 0ll) return ans;
        else ans += ".";
        
        while(remainder_ != 0){
            if(remainderToPos.find(remainder_) != remainderToPos.end()){
                ans = ans.substr(0, remainderToPos[remainder_]) + "(" + 
                      ans.substr(remainderToPos[remainder_]) + ")";
                return ans;
            }
            
            remainderToPos[remainder_] = ans.size();
            remainder_ *= 10;
            
            ans += to_string((remainder_ / divisor));
            
            remainder_ %= divisor;
        }
        
        return ans;
    }
};
