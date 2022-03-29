// SIEVE OF ERATOSTHENES
// Space complexity: O(n) - 197 ms, faster than 80.46% of C++ online submissions
//  Time complexity: O(n*log(log(n))) - 10.1 MB, less than 98.59% of C++ online submissions
class Solution {
public:
    int countPrimes(int n) {
        int numOfPrimes = 0;
        vector<bool> prime(n, true);
        
        for(int p = 2; p * p < n; p++){
            if(prime[p] == true){
                // Updating all multiples of p
                for(int i = p * p; i < n; i += p){
                    prime[i] = false;
                }
            }
        }
        
        for(int i = 2; i < n; i++){
            numOfPrimes += prime[i];
        }
        
        return numOfPrimes;
    }
};
