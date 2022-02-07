// Space complexity: O(N) - less than 45.90% of C++ online submissions
//  Time complexity: O(N) - faster than 91.11% of C++ online submissions
class Solution {
public:
    bool isPalindrome(string s) {
        string alphanumeric = "";
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(isalpha(s[i])) alphanumeric += tolower(s[i]);
            else if(isdigit(s[i])) alphanumeric += s[i];
        }
        
        for(int left = 0, right = (int)alphanumeric.size() - 1; left < right; left++, right--){
            if(alphanumeric[left] != alphanumeric[right]) return false;
        }
                
        return true;
    }
};
