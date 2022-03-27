// Space complexity: O(1) - 6 MB, less than 68.24% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        
        while(left < right){
            while((left < s.size()) &&
                  (s[left] < 'A') || 
                  (s[left] > 'Z' && s[left] < 'a') ||
                  (s[left] > 'z')) left++;
            
            while((right > 0) &&
                  (s[right] < 'A') || 
                  (s[right] > 'Z' && s[right] < 'a') ||
                  (s[right] > 'z')) right--;
            
            if(left < right) swap(s[left], s[right]);
            
            left++, right--;
        }
        
        return s;
    }
};
