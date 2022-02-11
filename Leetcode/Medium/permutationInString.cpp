// Space complexity: O(N + M) = O(N) - less than 17.14 % of C++ online submissions
//  Time complexity: O(26 * N) = O(N) - faster than 39.95 % of C++ online submissions
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         unordered_map<char, int> s1Freq, s2Freq;
        
//         if(s1.size() > s2.size()) return false;
        
//         for(unsigned int i = 0; i < s1.size(); i++){
//             s1Freq[s1[i]]++;
//             s2Freq[s2[i]]++;
//         }
                
//         if(s1Freq == s2Freq) return true;
        
//         for(unsigned int right = s1.size(), left = 0; right < s2.size(); right++, left++){
//             s2Freq[s2[left]]--;
//             if(s2Freq[s2[left]] == 0) s2Freq.erase(s2[left]);
            
//             s2Freq[s2[right]]++;
            
//             if(s1Freq == s2Freq) return true;
//         }
        
//         return false;
//     }
// };




// Space complexity: O(M + N) = O(N) - less than 22.21% of C++ online submissions
//  Time complexity: O(26 + N) = 0(N) - faster than 32.73% of C++ online submissions
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matches = 0;
        unordered_map<char, int> s1Freq, s2Freq;
        
        if(s1.size() > s2.size()) return false;
        
        for(unsigned int i = 0; i < s1.size(); i++){
            s1Freq[s1[i]]++;
            s2Freq[s2[i]]++;
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            if(s1Freq[c] == s2Freq[c]) matches++;
        }            
        
        for(unsigned int left = 0, right = s1.size(); right < s2.size(); left++, right++){
            if(matches == 26) return true;
            
            s2Freq[s2[left]]--;
            if(s2Freq[s2[left]] == s1Freq[s2[left]]) matches++;
            else if(s2Freq[s2[left]] == s1Freq[s2[left]] - 1) matches--;
            
            s2Freq[s2[right]]++;
            if(s2Freq[s2[right]] == s1Freq[s2[right]]) matches++;
            else if(s2Freq[s2[right]] == s1Freq[s2[right]] + 1) matches--;
        }
                
        return matches == 26;
    }
};
