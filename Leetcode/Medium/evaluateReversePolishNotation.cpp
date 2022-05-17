// Space complexity: O(N) - 12 MB, less than 21.01% of C++ online submissions
//  Time complexity: O(N) - 13 ms, faster than 59.25% of C++ online submissions
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int x, y;
        stack<int> operands;
        
        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                y = operands.top(), operands.pop();
                x = operands.top(), operands.pop();
                                
                if(token == "+") operands.push(x + y);
                else if(token == "-") operands.push(x - y);
                else if(token == "*") operands.push(x * y);
                else if(token == "/") operands.push(x / y);
            }
            else operands.push(stoi(token));
        }
        
        return operands.top();
    }
};
