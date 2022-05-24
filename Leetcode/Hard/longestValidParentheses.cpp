// Space complexity: O(N) - 7.1 MB, less than 78.83% of C++ online submissions
//  Time complexity: O(N) - 2 ms, faster than 89.84% of C++ online submissions
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int longest = 0;
//         stack<int> stck;
        
//         stck.push(-1); // this way i'll mantain a reference to the prev of the valid
//                        //sequence
        
//         for(int i = 0; i < (int)s.size(); i++){
//             if(s[i] == '(') stck.push(i);
//             else{
//                 stck.pop();
                
//                 if(stck.empty()) stck.push(i);
//                 else longest = max(longest, i - stck.top());
//             }
//         }
        
//         return longest;
//     }
// };



// Space complexity: O(1) - 6.8 MB, less than 88.01% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int longestValidParentheses(string s) {
        /*
                In this approach, we make use of two counters left and right. 
            First, we start traversing the string from the left towards the right 
            and for every ‘(’ encountered, we increment the left counter and for 
            every ‘)’ encountered, we increment the right counter. Whenever left 
            becomes equal to right, we calculate the length of the current valid 
            string and keep track of maximum length substring found so far. If 
            right becomes greater than left we reset left and right to 0.
        */
        
        int left = 0, right = 0, longest = 0;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] == '(') left++;
            else right++;
            
            if(left == right) longest = max(longest, 2 * right);
            else if(right > left) left = right = 0;
        }
        
        left = right = 0;
        for(int i = (int)s.size() - 1; i >= 0; i--){
            if(s[i] == '(') left++;
            else right++;
            
            if(left == right) longest = max(longest, 2 * left);
            else if(left > right) left = right = 0;
        }
        
        return longest;
    }
};
