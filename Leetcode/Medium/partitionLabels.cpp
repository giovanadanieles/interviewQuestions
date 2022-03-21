// Ref: https://www.youtube.com/watch?v=B7m8UmZE-vw

// Space complexity: O(26) = O(1) - 6.8 MB, less than 43.56% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 72.62% of C++ online submissions
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sizeCurPart = 0, endOfPart = 0;
        vector<int> ans;
        unordered_map<char, int> charLastIndex;
        
        // with this memoization we'll know if the char occurs any time "in the future"
        for(unsigned int i = 0; i < s.size(); i++){
            charLastIndex[s[i]] = i;
        }
        
        for(unsigned int i = 0; i < s.size(); i++){
            sizeCurPart++;
            endOfPart = max(endOfPart, charLastIndex[s[i]]);
            
            if(i == endOfPart){
                ans.push_back(sizeCurPart);
                
                sizeCurPart = 0;
            }
        }   
        
        return ans;
    }
};
