// Ref: https://www.youtube.com/watch?v=GR8Z1zaQzz0

// Space complexity: O(N) - 8.7 MB, less than 45.08% of C++ online submissions
//  Time complexity: O(N) - 26 ms, faster than 17.37% of C++ online submissions
// class Solution {
// public:
//     int calculate(string s){
//         char op = '+';
//         int curNum = 0;
//         stack<int> operations;
        
//         if(s.size() == 0) return 0;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(s[i] >= '0' && s[i] <= '9') curNum = curNum * 10 + (s[i] - '0');
            
//             if(((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == s.size() - 1){
//                 if(op == '+') operations.push(curNum);
//                 else if(op == '-') operations.push(-curNum);
//                 else if(op == '*'){
//                     curNum = operations.top() * curNum, operations.pop();
//                     operations.push(curNum);
//                 }
//                 else{
//                     curNum = operations.top() / curNum, operations.pop();
//                     operations.push(curNum);
//                 }
                
//                 op = s[i];
//                 curNum = 0;
//             }
//         }
        
//         while(!operations.empty()) curNum += operations.top(), operations.pop();
        
//         return curNum;
//     }
// };



// Space complexity: O(1) - 7.6 MB, less than 96.95% of C++ online submissions
//  Time complexity: O(N) - 8 ms, faster than 83.47% of C++ online submissions
class Solution {
public:
    int calculate(string s){
        char op = '+';
        int curNum = 0, sum = 0, last = 0;
        
        if(s.size() == 0) return 0;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9') curNum = curNum * 10 + (s[i] - '0');
            
            if(((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == s.size() - 1){
                if(op == '+') sum += last, last = curNum;
                else if(op == '-') sum += last, last = -curNum;
                else if(op == '*') last = last * curNum;
                else last = last / curNum;
                
                op = s[i];
                curNum = 0;
            }
        }
            
        return sum += last;
    }
};
