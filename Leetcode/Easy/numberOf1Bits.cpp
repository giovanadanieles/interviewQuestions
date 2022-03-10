// Space complexity: O(1) - less than 48.27% of C++ online submissions
//  Time complexity: O(N) - faster than 57.71% of C++ online submissions
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int ans = 0;
        
//         while(n > 0){
//             if(n % 2 == 1) ans++;
            
//             n /= 2;
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - less than 48.27% of C++ online submissions
//  Time complexity: O(N) - faster than 57.71% of C++ online submissions 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            ans += n & 1;
            
            n >>= 1;
        }
        
        return ans;
    }
};
