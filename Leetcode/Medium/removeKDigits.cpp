// Space complexity: O(N) - less than 22.62% of C++ online submissions
//  Time complexity: O(N) - faster than 52.62% of C++ online submissions
class Solution {
public:
    string removeKdigits(string num, int k) {
        int leadingZeros = 0;
        string ans = "";
        stack<int> s;
                        
        for(unsigned int i = 0; i < num.size(); i++){            
            while(!s.empty() && s.top() > num[i] - '0' && k > 0){
                s.pop();
                k--;
            }
            
            s.push(num[i] - '0');
        }
        
        while(k > 0){
            s.pop();
            k--;
        }
        
        while(!s.empty()){
            ans += s.top() + '0';
            s.pop();
        }
                
        reverse(ans.begin(), ans.end());
        
        for(unsigned int i = 0; ans[i] == '0'; i++) leadingZeros++;
        
        ans = ans.substr(leadingZeros);
        
        
        if(ans.size() == 0) return "0";
        else return ans;
    }
};
