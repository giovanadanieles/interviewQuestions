// Space complexity: O(N) - 11 MB, less than 34.17% of C++ online submissions
//  Time complexity: O(N) - 26 ms, faster than 27.58% of C++ online submissions
// class Solution {
// public:
//     string reverseWords(string s) {
//         string reversed = "";
//         stack<char> stck;
        
//         for(unsigned int i = 0; i < s.size(); i++){
//             if(s[i] != ' ') stck.push(s[i]);
//             else{
//                 while(!stck.empty()){
//                     reversed += stck.top();
                    
//                     stck.pop();
//                 }
                
//                 reversed += ' ';
//             }
//         }
        
//         while(!stck.empty()){
//             reversed += stck.top();

//             stck.pop();
//         }
        
//         return reversed;
//     }
// };



// Space complexity: O(1) - 9.6 MB, less than 75.46% of C++ online submissions
//  Time complexity: O(N) - 12 ms, faster than 92.36% of C++ online submissions
class Solution {
public:
    string reverseWords(string s) {
        int left, right, lSwap, rSwap;
        
        left = 0, right = 1;
        while(right < s.size()){
            while(right < s.size() && s[right] != ' ') right++;
            
            if(right != s.size() - 1) right--;
            
            lSwap = left, rSwap = right;
            
            while(lSwap < rSwap) swap(s[lSwap++], s[rSwap--]);
            
            left = right + 2;
            right = left + 1;
        }
        
        return s;
    }
};
