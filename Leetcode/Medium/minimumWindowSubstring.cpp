// Space complexity: O(N) - 17 MB, less than 7.88% of C++ online submissions
//  Time complexity: O(M+N) - 540 ms, faster than 5.02% of C++ online submissions
class Solution {
public:
    bool isValid(vector<int> &s, vector<int> &t){ // can be O(1)...
        for(unsigned int i = 0; i < t.size(); i++){
            if(s[i] < t[i]) return false;
        }
        
        return true;
    }
    
    string minWindow(string s, string t){
        int left, right, ansSize = INT_MAX;
        string ans;
        vector<int> mustHave(256, 0), have(256, 0);
        
        for(auto c : t) mustHave[c]++;
        
        for(left = 0, right = 0; left < s.size(); left++){
            while(right < s.size() && isValid(have, mustHave) == false) have[s[right++]]++;
            if(isValid(have, mustHave) == true && right - left < ansSize){
                ans = s.substr(left, right - left);
                ansSize = right - left;
            }
            
            have[s[left]]--;
        }
        
        return ans;
    }
};
