// Space complexity: O(N) - less than 52.40% of C++ online submissions
//  Time complexity: O(N) - faster than 75.62% of C++ online submissions
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<char> stck;
        stack<int> positions;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stck.push(s[i]);
                positions.push(i);   
            }
            else if(s[i] == ')'){
                if(!stck.empty() && stck.top() == '('){
                    stck.pop();
                    positions.pop();
                }
                else s[i] = '*';
            }
        }
        
        if(!stck.empty()){
            while(!positions.empty()){
                s[positions.top()] = '*';
                positions.pop();
            }
        }
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] != '*') ans += s[i];
        }
        
        return ans;
    }
};
