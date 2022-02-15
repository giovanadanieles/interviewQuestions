// Space complexity: O(M) - less than 44.65% of C++ online submissions
//  Time complexity: O(N * M), being M size of smallest string - faster than 75.19% of C++ online submissions
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         bool end = false;
//         char compare;
//         int minSize = INT_MAX, count;
//         string prefix = "";
        
//         for(unsigned int i = 0; i < strs.size(); i++){
//             if(strs[i].size() == 0) return prefix;
            
//             minSize = min(minSize, (int)strs[i].size());         
//         }
        
        
//         for(int i = 0; i < minSize && !end; i++){
//             count = 0;
//             compare = strs[0][i];
            
//             for(unsigned int j = 1; j < strs.size(); j++){
//                 if(compare == strs[j][i]) count++;
//                 else{
//                     end = true;
//                     break;
//                 }
//             }
                        
//             if(count == strs.size() - 1) prefix += strs[0][i];
//         }
        
//         return prefix;
//     }
// };



// Space complexity: O(M) - less than 44.65% of C++ online submissions
//  Time complexity: O(N * M), being M size of smallest string - faster than 42.42% of C++ online submissions
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        
        for(unsigned int i = 0; i < strs[0].size(); i++){
            for(unsigned int j = 1; j < strs.size(); j++){
                if(i == strs[j].size() || strs[0][i] != strs[j][i]) return prefix;
            }
            
            prefix += strs[0][i];
        }
        
        return prefix;
    }
};
