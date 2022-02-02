// Space complexity: O(1) - less than 94.03% of C++ online submissions
//  Time complexity: O(N) - faster than 67.43% of C++ online submissions
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(unsigned int i = 0, j = s.size() - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
