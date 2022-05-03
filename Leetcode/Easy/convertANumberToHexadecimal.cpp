// Space complexity: O(1) - 5.9 MB, less than 82.32% of C++ online submissions
//  Time complexity: O(1) - 2 ms, faster than 33.08% of C++ online submissions
class Solution {
public:
    string toHex(int num) {
        string ans = "";
        vector<char> decToHex = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        if(num == 0) return "0";
        
        while(num != 0 && ans.size() < 8){
            ans += decToHex[num & 15];
            num >>= 4;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
