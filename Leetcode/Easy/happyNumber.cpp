// Space complexity: O(logn) - less than 41.12% of C++ online submissions
//  Time complexity: O(logn) - faster than 56.68% of C++ online submissions
// class Solution {
// public:
//     bool isHappy(int n) {
//         int sum;
//         unordered_set<int> seen;
        
//         while(n != 1){
//             sum = 0;
            
//             while(n > 0){
//                 sum += (n % 10) * (n % 10);
                
//                 n /= 10;
//             }
            
//             n = sum;
            
//             if(seen.find(n) != seen.end()) return false;
//             else seen.insert(n);
//         }
        
//         return true;
//     }
// };



// FLOYD'S LOOP DETECTION ALGORITHM APPROACH
// Space complexity: O(1) - less than 84.75% of C++ online submissions
//  Time complexity: O(logn) - faster than 100.00% of C++ online submissions

class Solution {
public:
    int getSquaresSum(int n){
        int sum = 0;
        
        while(n > 0){
            sum += (n % 10) * (n % 10);

            n /= 10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> seen;
        int slow, fast;
        
        slow = n;
        fast = getSquaresSum(n);
        
        while(fast != 1 && slow != fast){
            slow = getSquaresSum(slow);
            fast = getSquaresSum(getSquaresSum(fast));
        }
        
        if(fast == 1) return true;
        else return false;
    }
};
