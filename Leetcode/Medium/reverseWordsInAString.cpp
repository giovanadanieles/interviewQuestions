// Space complexity: O(N), being N the number of chars - 7.6 MB, less than 52.66% of C++ online submissions
//  Time complexity: O(N) - 4 ms, faster than 82.60% of C++ online submissions
class Solution {
public:
    string reverseWords(string s) {
        string curWord, ans = "";
        stack<string> words;
        
        for(unsigned int i = 0; i < s.size(); i++){
            if(curWord != "" && s[i] == ' '){
                words.push(curWord);
                curWord = "";
            }
            else if(s[i] != ' ') curWord += s[i];
        }
        
        if(curWord != "") words.push(curWord);
        
        while(!words.empty()){
            words.size() == 1 ? ans += words.top() : ans += words.top() + " ";
            words.pop();
        }
        
        return ans;
    }
};
