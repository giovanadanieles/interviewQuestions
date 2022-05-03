// Space complexity: O(M + N) - 6.4 MB, less than 39.09% of C++ online submissions
//  Time complexity: O(M + N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> s1, s2;
        
//         for(unsigned int i = 0; i < max(s.size(), t.size()); i++){
//             if(i < s.size()){
//                 if(s[i] == '#'){
//                     if(!s1.empty()) s1.pop();
//                 } 
//                 else s1.push(s[i]);
//             }
            
//             if(i < t.size()){
//                 if(t[i] == '#'){
//                     if(!s2.empty()) s2.pop();
//                 }
//                 else s2.push(t[i]);
//             }
//         }
        
//         return s1 == s2;
//     }
// };



// Space complexity: O(1) - 6.3 MB, less than 37.50% of C++ online submissions
//  Time complexity: O(M + N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sIndex, tIndex, sSkip = 0, tSkip = 0;
        
        sIndex = s.size() - 1, tIndex = t.size() - 1;
        
        while(sIndex >= 0 || tIndex >= 0){
            while(sIndex >= 0){
                if(s[sIndex] == '#') sSkip++, sIndex--;
                else if(sSkip > 0) sSkip--, sIndex--;
                else break;
            }
            
            while(tIndex >= 0){
                if(t[tIndex] == '#') tSkip++, tIndex--;
                else if(tSkip > 0) tSkip--, tIndex--;
                else break;
            }
            
            if(sIndex >= 0 && tIndex >= 0 && s[sIndex] != t[tIndex]) return false;
            else if((sIndex  >= 0) != (tIndex >= 0)) return false;
            
            sIndex--, tIndex--;
        }
        
        return true;
    }
};
