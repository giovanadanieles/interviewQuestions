// Space complexity: O(N) - less than 30.35% of C++ online submissions
//  Time complexity: O(N) - faster than 42.06% of C++ online submissions
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left, right;
        unordered_set<char> alreadyUsed;
        
        if(s.size() == 0) return 0;
        
        for(left = 0, right = 0; right < s.size(); right++){
            while(alreadyUsed.find(s[right]) != alreadyUsed.end()){
                alreadyUsed.erase(s[left]);
                left++;
            }
            
            alreadyUsed.insert(s[right]);
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
