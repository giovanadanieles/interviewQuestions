// Space complexity: O(N) - 6.3 MB, less than 8.12% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int score = 0, mult;
//         stack<char> stck;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(stck.empty()) mult = 1;
            
//             if(s[i] == '('){
//                 mult = 1 << stck.size();
//                 stck.push(s[i]);
//             }
//             else{
//                 score += mult;
//                 mult = 0;
                
//                 stck.pop();
//             }
//         }
        
//         return score;
//     }
// };



// Space complexity: O(1) - 6.2 MB, less than 45.05% of C++ online submissions
//  Time complexity: O(N) - 2 ms, faster than 37.38% of C++ online submissions
// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int score = 0, opNum = 0, mult;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(opNum == 0) mult = 1;
            
//             if(s[i] == '('){
//                 mult = 1 << opNum;
//                 opNum++;
//             }
//             else{
//                 score += mult;
//                 mult = 0;
                
//                 opNum--;
//             }
//         }
        
//         return score;
//     }
// };



// Space complexity: O(1) - 6 MB, less than 83.25% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, opNum = 0;
        
        for(unsigned int i = 0; i < s.size(); i++){            
            if(s[i] == '(') opNum++;
            else{
                opNum--;
                if(s[i - 1] == '(') score += 1 << opNum;                
            }
        }
        
        return score;
    }
};
