// Space complexity: O(1) - less than 52.23% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, mod = 1000000007;
        
        /*
            ans = n! * 1 * 3 * 5 * ... * (2 * n - 1); 
        */ 
                
        for(int i = 1; i <= n; i++){
            ans *= i; //factorial (pickup counting)
            ans %= mod;
            
            ans *= (2 * i - 1); //1*3*...*(2*n-1) (delivery counting)
            ans %= mod;
        }
        
        return ans % mod;      
    }
};
