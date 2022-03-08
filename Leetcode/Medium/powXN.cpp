// Space complexity: O(log N) - less than 18.51% of C++ online submissions
//  Time complexity: O(log N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    double helper(double x, int n){
        if(x == 0) return 0;
        if(n == 0) return 1;
        
        double ans = myPow(x, n/2);
        ans = ans * ans;
        
        if(n % 2 == 1) return x * ans;
        return ans;
    }
    
    double myPow(double x, int n) {
        double ans;
        
        ans = helper(x, abs(n));
        
        if(n < 0) return 1 / ans;
        return ans;
    }
};
