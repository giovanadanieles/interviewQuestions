// Space complexity: O(N) - 14.1 MB, less than 10.33% of C++ online submissions
//  Time complexity: O(N) - 39 ms, faster than 40.84% of C++ online submissions
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        stack<pair<char, int>> stck;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(!stck.empty() && stck.top().first == s[i]) stck.push({s[i], stck.top().second + 1});
            else stck.push({s[i], 1});
            
            if(stck.top().second == k){
                for(unsigned int i = 0; i < k; i++) stck.pop();
            }
        }
        
        while(!stck.empty()){
            ans += stck.top().first;
            stck.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
