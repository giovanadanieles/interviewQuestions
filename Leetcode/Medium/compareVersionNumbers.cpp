// Space complexity: O(N) - less than 35.33% of C++ online submissions
//  Time complexity: O(N) - faster than 38.97% of C++ online submissions
class Solution {
public:
    int areDiff(int a, int b){
        if(a < b) return -1;
        else if(a > b) return 1;
        else return 0;
    }
    
    int compareVersion(string version1, string version2) {
        int curPosA = 0, curPosB = 0, ans;
        string a, b;
        
        while(curPosA < version1.size() && curPosB < version2.size()){
            a.clear(), b.clear();
            
            while(version1[curPosA] != '.' && curPosA < version1.size()){
                a += version1[curPosA];
                curPosA++;
            }
            
            while(version2[curPosB] != '.' && curPosB < version2.size()){
                b += version2[curPosB];
                curPosB++;
            }
                                    
            ans = areDiff(stoi(a), stoi(b));
            if(ans != 0) return ans;
            
            curPosA++, curPosB++;
        }
                
        ans = 0;
        if(curPosA < version1.size()){
            while(curPosA < version1.size()){
                if(version1[curPosA] != '0' && version1[curPosA] != '.'){
                    ans = 1;
                    break;
                }
                
                curPosA++;
            }
        }
        else if(curPosB < version2.size()){
            while(curPosB < version2.size()){
                if(version2[curPosB] != '0' && version2[curPosB] != '.'){
                    ans = -1;
                    break;
                }
                
                curPosB++;
            }
        }
        
        return ans;
    }
};
