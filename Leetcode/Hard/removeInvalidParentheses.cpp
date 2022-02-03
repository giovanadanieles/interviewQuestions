// Space complexity: O(2 ^ N) - less than 27.38% of C++ online submissions
//  Time complexity: O(N * 2 ^ N) - faster than 22.00% of C++ online submissions
class Solution {
public:
    vector<string> ans;
    unordered_map<string, int> orderVisited;
    
    int numOfInvalidParentheses(string s){
        stack<char> stck;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] == '(') stck.push(s[i]);
            else if(s[i] == ')'){
                if(!stck.empty() && stck.top() == '(') stck.pop();
                else stck.push(s[i]);
            }
        }
        
        return stck.size();
    }
    
    void solve(string s, int numOfParentheses){
        if(numOfParentheses < 0) return;
        
        if(orderVisited[s] != 0) return;
        else orderVisited[s]++;
        
        if(numOfParentheses == 0){
            if(numOfInvalidParentheses(s) == 0) ans.push_back(s);
            return;
        }
        
        for(unsigned int i = 0; i < s.size(); i++){
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            
            solve(left + right, numOfParentheses - 1);
        }
        
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        //  First: count num of invalid parentheses
        // Second: recursively remove this amount of parentheses
        
        solve(s, numOfInvalidParentheses(s));
        
        return ans;
    }
};
