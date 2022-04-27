// Space complexity: O(N) - 6.9 MB, less than 8.74% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 61.16% of C++ online submissions
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         unordered_map<char, int> usedInS;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             usedInS[s[i]]++;
//         }
        
//         for(unsigned int i = 0; i < t.size(); i++){
//             if(usedInS[t[i]] == 0) return t[i];
//             else usedInS[t[i]]--;
//         }
        
//         return '*';
//     }
// };



// Space complexity: O(1) - 6.7 MB, less than 25.86% of C++ online submissions
//  Time complexity: O(N) - 7 ms, faster than 27.02% of C++ online submissions
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int ascii = 0;
        
//         for(char c : s) ascii += c;
//         for(char c : t) ascii -= c;
        
//         return (char)(-ascii);
//     }
// };



// Space complexity: O(1) - 6.6 MB, less than 68.17% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        
        for(char c : s) ans ^= c;
        for(char c : t) ans ^= c;
        
        return ans;
    }
};
