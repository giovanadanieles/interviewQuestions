// Space complexity: O(4 ^ N), being N digits_size - 6.4 MB, less than 84.98% of C++ online submissions
//  Time complexity: O(4 ^ N) - 4 ms, faster than 26.04% of C++ online submissions
class Solution {
public:
    void backtracking(unordered_map<int, vector<char>> &numToChar, vector<string> &ans, string &digits, string curComb){
        if(curComb.size() == digits.size()){
            ans.push_back(curComb);
            return;
        }
        
        unsigned int index = curComb.size();
        for(unsigned int i = 0; i < numToChar[digits[index] - '0'].size(); i++){
            curComb.push_back(numToChar[digits[index] - '0'][i]);
            
            backtracking(numToChar, ans, digits, curComb);
            
            curComb.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        char c = 'a';
        vector<string> ans;
        unordered_map<int, vector<char>> numToChar;
        
        if(digits.size() == 0) return ans;
        
        for(int i = 2; i <= 9; i++){
            for(int j = 0; j < 3; j++) numToChar[i].push_back(c++);
            
            if(i == 7 || i == 9) numToChar[i].push_back(c++);
        }
        
        backtracking(numToChar, ans, digits, "");
        
        return ans;
    }
};
