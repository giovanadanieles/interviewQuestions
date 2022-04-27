// Space complexity: O(26) = O(1) - 87.1 MB, less than 20.48% of C++ online submissions
//  Time complexity: O(N ^ 3) - 658 ms, faster than 11.87% of C++ online submissions
class Solution {
public:
    bool isNice(string s){
        /*
        *   0: has nothing
        *   1: has lowercase
        *   2: has uppercase
        *   3: have both
        */
        unordered_map<char, int> used;

        for(unsigned int i = 0; i < s.size(); i++){
            if(s[i] < 'a'){
                if(used[tolower(s[i])] == 0) used[tolower(s[i])] = 2;
                else if(used[tolower(s[i])] == 1) used[tolower(s[i])] = 3;
            }
            else{
                if(used[s[i]] == 0) used[s[i]] = 1;
                else if(used[s[i]] == 2) used[s[i]] = 3;
            }
        }

        for(auto it = used.begin(); it != used.end(); it++){
            if(it->second != 3) return false;
        }
        
        return true;
    }
    
    string longestNiceSubstring(string s){
        string longestSub = "", curSub = ""; 
        
        for(unsigned int left = 0; left < s.size(); left++){
            curSub = s[left];
            
            for(unsigned int right = left + 1; right < s.size(); right++){
                curSub += s[right];
                
                if(isNice(curSub) && curSub.size() > longestSub.size()){ 
                    longestSub = curSub;
                }
            }
        }
                
        return longestSub;
    }
};
