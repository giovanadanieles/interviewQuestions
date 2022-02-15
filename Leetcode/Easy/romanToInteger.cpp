// Space complexity: O(1) - less than 40.58% of C++ online submissions
//  Time complexity: O(N) - faster than 67.92% of C++ online submissions
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> romanToInt;
        
        romanToInt['I'] = 1;
        romanToInt['V'] = 5;
        romanToInt['X'] = 10;
        romanToInt['L'] = 50;
        romanToInt['C'] = 100;
        romanToInt['D'] = 500;
        romanToInt['M'] = 1000;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(i + 1 < s.size() && romanToInt[s[i]] < romanToInt[s[i + 1]]){
                ans += romanToInt[s[i + 1]] - romanToInt[s[i]];
                i++;
            }
            else ans += romanToInt[s[i]];
        }
        
        return ans;
    }
};
