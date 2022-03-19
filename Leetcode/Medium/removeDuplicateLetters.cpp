// Space complexity: O(N) - 7.1 MB, less than 14.11% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 61.45% of C++ online submissions
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        unordered_set<char> alreadySeen;
        vector<int> frequencies(26, 0);
        deque<char> dq;
        
        // can the char at the top of the stack be popped and added latter in a better condition?
        
        if(s.size() == 1) return s;
        
        for(unsigned int i = 0; i < s.size(); i++){
            frequencies[s[i] - 'a']++;
        }     
        
        for(unsigned int i = 0; i < s.size(); i++){
            while(!dq.empty() && frequencies[dq.back() - 'a'] > 0 && s[i] <= dq.back() && 
                  alreadySeen.find(s[i]) == alreadySeen.end()){
                
                alreadySeen.erase(dq.back());
                dq.pop_back();
            }
        
            if(alreadySeen.find(s[i]) == alreadySeen.end()){
                alreadySeen.insert(s[i]);
                dq.push_back(s[i]);
            }
            
            frequencies[s[i] - 'a']--;
        }
        
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        } 
            
        return ans;
    }
};
