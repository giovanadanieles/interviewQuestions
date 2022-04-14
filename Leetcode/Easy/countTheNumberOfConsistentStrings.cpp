// Space complexity: O(26) = O(1) - 30.2 MB, less than 62.95% of C++ online submissions
//  Time complexity: O(N * M) - 66 ms, faster than 73.87% of C++ online submissions
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0, index;
        unordered_set<char> allowedChars;
        
        for(char c : allowed) allowedChars.insert(c);
        
        for(string word : words){
            for(index = 0; index < word.size(); index++){
                if(allowedChars.find(word[index]) == allowedChars.end()) break;
            }
            
            if(index == word.size()) count++;
        }
        
        return count;
    }
};
