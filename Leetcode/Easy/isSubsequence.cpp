// Space complexity: O(1) - less than 33.56% of C++ online submissions
//  Time complexity: O(N) - faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unsigned int sIndex = 0, tIndex = 0;
                
        while(tIndex < t.size()){
            if(s[sIndex] == t[tIndex]) sIndex++, tIndex++;
            else tIndex++;
        }
        
        if(sIndex != s.size()) return false;
        else return true;
    }
};
