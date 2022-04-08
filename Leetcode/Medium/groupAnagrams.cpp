// Space complexity: O(N) - 27.4 MB, less than 10.22% of C++ online submissions
//  Time complexity: O(N * max(size(N), logN)) - 71 ms, faster than 27.41% of C++ online submissions
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         map<vector<int>, vector<string>> anagrams;
        
//         for(unsigned int i = 0; i < strs.size(); i++){
//             vector<int> word(26,0);
            
//             for(unsigned int j = 0; j < strs[i].size(); j++){
//                 word[strs[i][j] - 'a']++;
//             }
            
//             anagrams[word].push_back(strs[i]);
//         }
        
//         for(auto it = anagrams.begin(); it != anagrams.end(); it++){
//             vector<string> temp;
            
//             for(unsigned int i = 0; i < it->second.size(); i++){
//                 temp.push_back(it->second[i]);
//             }
            
//             ans.push_back(temp);
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N * K) - 18.3 MB, less than 94.56% of C++ online submissions
//  Time complexity: O(N K log K) - 36 ms, faster than 85.39% of C++ online submissions
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int index = 0;
        vector<vector<string>> ans;
        unordered_map<string, int> anagrams;
        
        for(auto str : strs){
            sort(str.begin(), str.end());
            
            auto it = anagrams.find(str);
            
            if(it == anagrams.end()){
                ans.push_back({strs[index]});
                anagrams[str] = ans.size() - 1;
            }
            else ans[it->second].push_back(strs[index]);
            
            index++;
        }
        
        return ans;
    }
};
