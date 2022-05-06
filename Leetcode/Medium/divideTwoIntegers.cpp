// Ref: https://www.youtube.com/watch?v=6kFp_s_UtPE
// Space complexity: O(1) - 5.7 MB, less than 99.91% of C++ online submissions
//  Time complexity: O(logN) - 4 ms, faster than 50.81% of C++ online submissions
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0, a, b, temp, mult;
        bool isNegative = true;
        
        if((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor > 0)) isNegative = false;
        
        a = divisor, b = dividend;
        
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        
        while(b >= a){
            temp = a;
            mult = 1;
            
            while(b >= temp){
                b -= temp;
                ans += mult;
                
                mult += mult;
                temp += temp;
            }
        }
        
        if(isNegative == true) ans = -ans;
        
        if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;
        else return ans;
    }
};
