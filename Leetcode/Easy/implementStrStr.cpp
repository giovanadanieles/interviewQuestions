// Space complexity: O(M) - less than 18.40% of C++ online submissions
//  Time complexity: O(N * M), being N haystack size and M needle size - faster than 30.16% of C++ online submissions
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         string compare;
        
//         if(needle.size() == 0) return 0;
        
//         compare = haystack.substr(0, needle.size());
        
//         if(compare == needle) return 0;
        
//         for(unsigned int i = needle.size(); i < haystack.size(); i++){
//             compare = compare.substr(1);
//             compare += haystack[i];
            
//             if(compare == needle) return i - (needle.size() - 1);
//         }
        
//         return -1;
//     }
// };



// Space complexity: O(N) - less than 31.00% of C++ online submissions
//  Time complexity: O(2N + M) - faster than 87.71% of C++ online submissions
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
        //LPS = longest prefix suffix
        vector<int> lps(needle.size(), 0);
        unsigned int prevLPS = 0, curPos = 1;  //LPS pointers
        
        //Complexity of while loop: O(2 * N), being N needle size
        while(curPos < needle.size()){
            if(needle[curPos] == needle[prevLPS]){
                lps[curPos] = prevLPS + 1;
                prevLPS++, curPos++;
            }
            else if(prevLPS == 0){
                    lps[curPos] = 0;
                    curPos++;
                }
            else prevLPS = lps[prevLPS - 1];
        }
        
        //Pointers for needle and haystack
        unsigned int curHay = 0, curNeedle = 0;
        
        //Complexity of while loop: O(M), being M haystack size
        while(curHay < haystack.size()){
            if(haystack[curHay] == needle[curNeedle]){ 
                curHay++, curNeedle++;
            }
            else if(curNeedle == 0) curHay++;
            else curNeedle = lps[curNeedle - 1];
           
            if(curNeedle == needle.size()) return curHay - needle.size();
        }
        
        return -1;
    }
};
