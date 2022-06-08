// Space complexity: O(1) - 6.3 MB, less than 26.79% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     bool isPalindrome(string s){
//         int left, right;
        
//         left = 0, right = (int)s.size() - 1;
//         while(left < right){
//             if(s[left] != s[right]) return false;
            
//             left++, right--;
//         }
        
//         return true;
//     }
    
//     int removePalindromeSub(string s) {
//         return isPalindrome(s) ? 1 : 2;
//     }
// };



// Space complexity: O(1) - 6.2 MB, less than 26.79% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int removePalindromeSub(string s) {
        int left, right;
        
        left = 0, right = (int)s.size() - 1;
        while(left < right){
            if(s[left] != s[right]) return 2;
            
            left++, right--;
        }
        
        return 1;
    }
};
