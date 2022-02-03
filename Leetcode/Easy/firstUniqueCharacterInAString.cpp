// Space complexity: O(A), being A the number of dif characters in the string - faster than 5.01% of C++ online submissions
//  Time complexity: O(N) - faster than 5.01% of C++ online submissions
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int ans = -1;
//         //character, index of first appearance, num of appearances 
//         unordered_map<char, pair<int, int>> characters;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(characters[s[i]].second == 0) characters[s[i]].first = i;
//             characters[s[i]].second++;
//         }
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(characters[s[i]].second == 1){
//                 ans = characters[s[i]].first;
//                 break;
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(1) - less than 90.82% of C++ online submissions
//  Time complexity: O(N) - faster than 71.09% of C++ online submissions
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> frequency(26, 0);
        
        for(unsigned int i = 0; i < s.size(); i++){
            frequency[s[i] - 'a']++;
        }
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(frequency[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};
