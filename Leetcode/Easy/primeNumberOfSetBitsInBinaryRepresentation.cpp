// Space complexity: O(1) - 6 MB, less than 31.97% of C++ online submissions
//  Time complexity: O(N log N) - 12 ms, faster than 67.80% of C++ online submissions
class Solution {
public:
    // O(N log (log N))
    void sieve(vector<bool> &primes){
        for(int i = 2; i * i <= primes.size(); i++){
            if(primes[i] == true){
                for(int j = i * 2; j <= primes.size(); j += i){
                    primes[j] = false;
                }
            }
        }
    }
    
    int countPrimeSetBits(int left, int right) {
        int curNum, numOfOnes, ans = 0;
        vector<bool> primes(30, true);
        
        primes[0] = false;
        primes[1] = false;
        
        sieve(primes);
        
        for(int i = left; i <= right; i++){
            curNum = i, numOfOnes = 0;
            
            while(curNum > 0){
                numOfOnes += curNum % 2;
                
                curNum /= 2;
            }
            
            if(primes[numOfOnes] == true) ans++;
        }
        
        return ans;
    }
};
