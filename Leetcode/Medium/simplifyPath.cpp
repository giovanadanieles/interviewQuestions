// Space complexity: O(N) - 9.9 MB, less than 37.71% of C++ online submissions
//  Time complexity: O(N) - 7 ms, faster than 72.17% of C++ online submissions
class Solution {
public:
    string simplifyPath(string path) {
        string curPath = "", ans = "";
        stack<string> dir, revDir;
        
        path += "/";
        
        for(unsigned int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(curPath == ".."){
                    if(!dir.empty()) dir.pop();
                }
                else if(curPath != "" && curPath != ".")
                    dir.push(curPath);
                
                curPath = "";
            }
            else curPath += path[i];     
        }
        
        if(dir.empty()) ans += "/";
        else{
            while(!dir.empty()){
                revDir.push(dir.top());
                dir.pop();
            }
            
             while(!revDir.empty()){
                ans += "/" + revDir.top();
                revDir.pop();
            }
        }
        
        return ans;
    }
};
