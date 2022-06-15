// Ref: https://www.youtube.com/watch?v=w3qJUxQvsMs
// Space complexity: O(N*L^2) - 21.7 MB, less than 33.94% of C++ online submissions
//  Time complexity: O(N*L^2) - 105 ms, faster than 74.65% of C++ online submissions
class Solution {
public:
    unordered_set<string> existingWords;
    unordered_map<string, int> wordAndMaxChain;
    
    int findChain(string word){
        if(existingWords.find(word) == existingWords.end()) return 0;
        else if(wordAndMaxChain.find(word) != wordAndMaxChain.end()){
            return wordAndMaxChain[word];
        }
        else{
            int mx = 0;
            string newStr;
            
            for(unsigned int index = 0; index < word.size(); index++){
                newStr = word.substr(0, index) + word.substr(index + 1);
                
                mx = max(mx, findChain(newStr) + 1);
            }
            
            wordAndMaxChain[word] = mx;
            
            return mx;
        }
    }
    
    int longestStrChain(vector<string>& words) {
        int longestChainSz = 0;
        
        for(auto word : words) existingWords.insert(word);
        
        for(auto word : words) findChain(word);
        
        for(auto it = wordAndMaxChain.begin(); it != wordAndMaxChain.end(); it++){
            longestChainSz = max(longestChainSz, it->second);
        }
        
        return longestChainSz;
    }
};
