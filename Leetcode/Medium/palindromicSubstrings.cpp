// Space complexity: O(1) - 6.3 MB, less than 69.07% of C++ online submissions
//  Time complexity: O(N ^ 2) - 4 ms, faster than 86.92% of C++ online submissions
class Solution {
public:
    int countSubstrings(string s) {
        /*
            -> first, we count the number of different letters in the string; this will be the number
            of palindromes with size = 1
            -> next, we go through each position and analyze possible palindromes of even and odd sizes.
        */
        
        int numOfPalindromes = s.size(), left, right;
        
        for(unsigned int i = 0; i < s.size(); i++){
            
            // analyzing even length palindromes
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                numOfPalindromes++;
                
                left--, right++;
            }
            
            // analyzing odd length palindromes
            left = i - 1, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                numOfPalindromes++;
                
                left--, right++;
            }
        }
                
        return numOfPalindromes;
    }
};
