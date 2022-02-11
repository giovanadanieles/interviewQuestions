// Space complexity: O(N + M) = O(N) - memory usage beats 17.14 % of cpp submissions
//  Time complexity: O(26 * N) = O(N) - beats 39.95 % of cpp submissions
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Freq, s2Freq;
        
        if(s1.size() > s2.size()) return false;
        
        for(unsigned int i = 0; i < s1.size(); i++){
            s1Freq[s1[i]]++;
            s2Freq[s2[i]]++;
        }
                
        if(s1Freq == s2Freq) return true;
        
        for(unsigned int right = s1.size(), left = 0; right < s2.size(); right++, left++){
            s2Freq[s2[left]]--;
            if(s2Freq[s2[left]] == 0) s2Freq.erase(s2[left]);
            
            s2Freq[s2[right]]++;
            
            if(s1Freq == s2Freq) return true;
        }
        
        return false;
    }
};
