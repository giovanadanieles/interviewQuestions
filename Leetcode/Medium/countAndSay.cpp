/*
We can assume that in worst case the current string does not have any adjacent chars that are similar, say '121'. 
With this logic, the length of the string would get doubled every time i.e. '111211'. So the length of the strings 
would be 1,2,4,8,16,... - this gives us a worst case complexity of O(2^n) although the actually time complexity 
would be much smaller.
*/

// Space complexity: O(2 ^ N) - 6.7 MB, less than 57.65% of C++ online submissions
//  Time complexity: O(2 ^ N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    string countAndSay(int n) {
        int stage = 1;
        string ans = "";
        vector<pair<char, int>> stck;
        
        if(n == 1) return "1";
        
        stck.push_back({'1', 1});
        
        while(stage < n){
            ans = "";
            
            while(!stck.empty()){
                ans += stck.back().second + '0';
                ans += stck.back().first;
                
                stck.pop_back();
            }
            
            for(int i = ans.size() - 1; i >= 0; i--){
                if(!stck.empty() && stck.back().first == ans[i]) stck.back().second++;
                else stck.push_back({ans[i], 1});
            }
            
            stage++;
        }
        
        return ans;
    }
};
