// Ref: https://www.youtube.com/watch?v=XYQecbcd6_c

// Space complexity: O(N) - 24.6 MB, less than 44.34% of C++ online submissions
//  Time complexity: O(N ^ 2) - 32 ms, faster than 77.13% of C++ online submissions
class Solution {
public:
    string longestPalindrome(string s) {
        int ansLen = 0, left, right;
        string ans;
        
        for(unsigned int i = 0; i < s.size(); i++){
            //veryfing odd length palindromes
            left = right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(right - left + 1 > ansLen){
                    ansLen = right - left + 1;
                    ans = s.substr(left, right - left + 1);
                }
                
                left--, right++;
            }
            
            //veryfing even length palindromes
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(right - left + 1 > ansLen){
                    ansLen = right - left + 1;
                    ans = s.substr(left, right - left + 1);
                }
                
                left--, right++;
            }
        }
        
        return ans;
    }
};
