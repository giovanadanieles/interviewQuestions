// Space complexity: O(1) - faster than 43.40% of C++ online submissions
//  Time complexity: O(log10(N)) - less than 75.28% of C++ online submissions
// class Solution {
// public:
//     int ans;
    
//     void solve(int num){    
//         if(num < 10){
//             ans = num;
//             return;
//         }
        
//         int sum = 0;
//         while(num > 0){
//             sum += num % 10;
            
//             num /= 10;
//         }
        
//         solve(sum);
        
//         return;        
//     }
    
//     int addDigits(int num) {
//         solve(num);
        
//         return ans;
//     }
// };



// Space complexity: O(1) - less than 25.31% of C++ online submissions
//  Time complexity: O(1) - faster than 100.00% of C++ online submissions
class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
};
