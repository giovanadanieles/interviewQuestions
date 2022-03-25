// Space complexity: O(1) - 7 MB, less than 53.85% of C++ online submissions
//  Time complexity: O(N) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    int myAtoi(string s) {
        int curIndex = 0, signal = 1;
        long long ans = 0;
        
        if(s.size() == 0) return (int)ans;
        
        while(s[curIndex] == ' ') curIndex++;
        
        if(s[curIndex] == '-' || s[curIndex] == '+'){
            if(s[curIndex] == '-') signal = -1;
            
            curIndex++;
        }  
        
        if(s[curIndex] < '0' || s[curIndex] > '9') return (int)ans;
                
        while(s[curIndex] != ' ' && curIndex < s.size()){ 
            if(s[curIndex] < '0' || s[curIndex] > '9') return (int)(signal * ans);
            
            ans = ans * 10 + s[curIndex] - '0';
            
            if(signal * ans >= INT_MAX) return INT_MAX;
            else if(signal * ans <= INT_MIN) return INT_MIN;
            
            curIndex++;
        }
        
        ans *= signal;
        
        return (int)ans;
    }
};
