// Space complexity: O(P)
// Time complexity: O(S * P)
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int window, numChars = 0, cpNumChars, i, j;
//         vector<int> ans;
//         unordered_map<char, int> lettersUsed, cpLettersUsed;
        
//         for(unsigned int i = 0; i < p.size(); i++){
//             lettersUsed[p[i]]++;
//             numChars++;
//         }
        
//         window = (int)p.size();
        
//         for(int i = 0; i < (int)s.size() - window + 1; i++){
//             cpLettersUsed = lettersUsed;
//             cpNumChars = numChars;
            
//             for(j = i; j < i + window; j++){
//                 if(cpLettersUsed[s[j]] > 0){
//                     cpLettersUsed[s[j]]--;
//                     cpNumChars--;
//                 }
//                 else break;
//             }
            
//             if(j == i + window && cpNumChars == 0) ans.push_back(i);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(P) - less than 15.05% of C++ online submissions
//  Time complexity: O(S) - faster than 12.44% of C++ online submissions
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> pCount, sCount;
        
        if(p.size() > s.size()) return ans;
        
        for(unsigned int i = 0; i < p.size(); i++){
            pCount[p[i]]++;   
            sCount[s[i]]++;
        }
        
        if(pCount == sCount) ans.push_back(0);
        
        for(int left = 1, right = (int)p.size(); right < (int)s.size(); left++, right++){
            sCount[s[left - 1]]--;
            sCount[s[right]]++;
            
            if(sCount[s[left -1]] == 0) sCount.erase(s[left -1]);
            
            if(pCount == sCount) ans.push_back(left);
        }
        
        return ans;
    }
};
