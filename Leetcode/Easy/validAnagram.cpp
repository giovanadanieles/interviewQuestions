// Space complexity: O(A) [A = size of alphabet] - less than 46.65% of C++ online submissions
//  Time complexity: O(N) - faster than 44.76% of C++ online submissions
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         unsigned int nLetters = 0;
//         unordered_map<char, int> vocabulary;
        
//         if(t.size() < s.size() || t.size() > s.size()) return false;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             vocabulary[s[i]]++;
//         }
        
//         for(unsigned int i = 0; i < t.size(); i++){
//             if(vocabulary[t[i]] > 0){
//                 vocabulary[t[i]]--;
//                 nLetters++;
//             }
//             else return false;
//         }
        
//         return true;
//     }
// };


// Space complexity: O(1) - less than 94.75% of C++ online submissions
//  Time complexity: O(N) - faster than 62.77% of C++ online submissions
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vocabulary(26, 0);
        
        if(t.size() != s.size()) return false;
        
        for(unsigned int i = 0; i < s.size(); i++){
            vocabulary[s[i] - 'a']++;
            vocabulary[t[i] - 'a']--;
        }
        
        for(unsigned int i = 0; i < vocabulary.size(); i++){
            if(vocabulary[i] != 0) return false;
        }
        
        return true;
    }
};
