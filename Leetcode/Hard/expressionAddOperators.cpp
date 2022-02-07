// Memory Usage: 115.8 MB, less than 18.29% of C++ online submissions
//      Runtime: 752 ms, faster than 21.26% of C++ online submissions
class Solution {
public:
    vector<string> ans;
    
    void dfs(int curIndex, string path, long long ansSoFar, long long prevNum, string& s, int target){
        if(curIndex == s.size()){
            if(ansSoFar == target) ans.push_back(path);
            return;
        }
        
        for(int i = curIndex; i < s.size(); i++){
            if(i > curIndex && s[curIndex] == '0') break;
            
            long long curNum = stoll(s.substr(curIndex, i - curIndex + 1));
            
            // first number, no operator
            if(curIndex == 0) dfs(i + 1, path + to_string(curNum), curNum, curNum, s, target);
            else{
                dfs(i + 1, path + "+" + to_string(curNum), ansSoFar + curNum, curNum, s, target);
                dfs(i + 1, path + "-" + to_string(curNum), ansSoFar - curNum, -curNum, s, target);
                dfs(i + 1, path + "*" + to_string(curNum), ansSoFar - prevNum + prevNum * curNum,                         prevNum * curNum, s, target);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        dfs(0, "", 0LL, 0LL, num, target);
                
        return ans;
    }
};
