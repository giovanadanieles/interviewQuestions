// Space complexity: O(1) - 20.6 MB, less than 26.99% of C++ online submissions
//  Time complexity: O(N * N * M) - 167 ms, faster than 31.49% of C++ online submissions
// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         bool found;
//         int ans = 0;
        
//         for(unsigned int i = 0; i < words.size(); i++){
//             vector<int> lettersUsed(26, 0);
            
//             for(auto character : words[i]) lettersUsed[character - 'a']++;
            
//             for(unsigned int j = i + 1; j < words.size(); j++){   
//                 found = true;
                
//                 for(auto character : words[j]) if(lettersUsed[character - 'a'] > 0){
//                     found = false;
//                     break;
//                 }
                
//                 if(found == true) ans = max(ans, (int)(words[i].size() * words[j].size()));
//             }
//         }
        
//         return ans;
//     }
// };



// Ref: https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100
// Space complexity: O(N) - 15.6 MB, less than 79.69% of C++ online submissions
//  Time complexity: O(n*(N+n)), being n words sz and N avg word[i] sz - 60 ms, faster than 70.18% of C++ online submissions
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> mask(words.size(), 0);
        
        for(unsigned int i = 0; i < words.size(); i++){
            for(auto character : words[i]) mask[i] |= 1 << (character - 'a');
            
            for(unsigned int j = 0; j < i; j++){
                if((mask[i] & mask[j]) == 0) ans = max(ans, (int)(words[i].size() * words[j].size()));
            }
        }
        
        return ans;
    }
};
