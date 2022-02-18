// Space complexity: O(26) - less than 74.64% of C++ online submissions
//  Time complexity: O(N) - faster than 73.67% of C++ online submissions

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> lettersFrequencies(26, 0);
        
        if(magazine.size() < ransomNote.size()) return false;
        
        for(unsigned int i = 0; i < magazine.size(); i++){
            lettersFrequencies[magazine[i] - 'a']++;
            if(i < ransomNote.size()) lettersFrequencies[ransomNote[i] - 'a']--;
        }
        
        for(unsigned int i = 0; i < lettersFrequencies.size(); i++){
            if(lettersFrequencies[i] < 0) return false;
        }
        
        return true;
    }
};
