// Space complexity: O(1) - 6.5 MB, less than 30.22% of C++ online submissions 
//  Time complexity: O(N) - 6 ms, faster than 28.23% of C++ online submissions
// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         unordered_set<char> usedChars;
//         int goodSub = 0, left, right;
        
//         if(s.size() < 3) return goodSub;
        
//         usedChars.insert(s[0]);
//         usedChars.insert(s[1]);
//         usedChars.insert(s[2]);
        
//         for(left = 0, right = 3; right < s.size(); left++, right++){
//             if(usedChars.size() == 3) goodSub++;
            
//             if(s[right - 1] != s[left] && s[right - 2] != s[left]) usedChars.erase(s[left]);
//             usedChars.insert(s[right]);
//         }
//         if(usedChars.size() == 3) goodSub++;
        
//         return goodSub;
//     }
// };



// Space complexity: O(1) - 6.2 MB, less than 46.26% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 45.97% of C++ online submissions
class Solution {
public:
    int countGoodSubstrings(string s) {
        int size, goodSub = 0;
        
        size = s.size();
        
        for(int i = 0; i < size - 2; i++){
            if(s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2]) continue;
            else goodSub++;
        }
        
        return goodSub;
    }
};
