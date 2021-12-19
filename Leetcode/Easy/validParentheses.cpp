/* 
  Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
  Memory Usage: 6.5 MB, less than 10.01% of C++ online submissions for Valid Parentheses.
  
  Memory complexity: O(N)
    Time complexity: O(N)

*/

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        char top;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                stack.push(s[i]);
            }
            else{
                if(stack.empty()) return false;
                
                top = stack.top();
                stack.pop();
                
                switch(s[i]){
                    case ']':
                        if(top != '[') return false;
                    break;
                        
                    case ')':
                        if(top != '(') return false;
                    break;
                        
                    case '}':
                        if(top != '{') return false;
                    break;
                }
            }
        }
        
        if(!stack.empty()) return false;
        else return true;
    }
};
