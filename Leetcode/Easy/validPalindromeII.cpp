// Version 1:
//              runtime faster than 88.24% of cpp submissions 
//              memory usage less than 52.64% of cpp submissions

// bool validPalindrome(string s) {
//         unsigned int left = 0;
//         unsigned int right = s.size() - 1;
//         int deleted = 0;
        
//         while(left < right){
//             if(s.size() % 2 == 0 && left == right - 1) return true;
            
//             if(s[left] != s[right]){
//                 if(s[left + 1] != s[right] && s[left] != s[right - 1]) return false;
                
//                 if(s[left + 1] == s[right] && s[right - 1] == s[left]){
//                     if(s[left + 2] == s[right - 3]){
//                         right--, deleted++;
//                     }
//                     else if(s[right - 2] == s[left + 3]){
//                         left++, deleted++;
//                     }
//                     else return false;
//                 }
                
//                 else if(s[left + 1] == s[right]){
//                     left++, deleted++;
//                 }
//                 else if(s[left] == s[right - 1]){
//                     right--, deleted++;
//                 }
                
//                 if(deleted > 1) return false;
//             }
            
            
//             left++, right--;
//         }
        
//         return true;
// }



// Ref: https://www.youtube.com/watch?v=L_74qbyPHXE

// Space complexity: O(1) - 24.1 MB, less than 18.74% of C++ online submissions
//  Time complexity: O(N) - 60 ms, faster than 80.88% of C++ online submissions
class Solution {
public:
    bool checkPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            
            left++, right--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
       int left, right;
        
        left = 0, right = s.size() - 1;
        
        while(left < right){
            if(s[left] != s[right]){
                return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1);
            }
            
            left++, right--;
        }
        
        return true;
    }
};
