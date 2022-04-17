// Space complexity: O(V + E) - 67.2 MB, less than 45.57% of C++ online submissions
//  Time complexity: O(V + E) - 212 ms, faster than 63.96% of C++ online submissions
// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         unordered_map<int, vector<int>> whoTrustsWhom;
//         unordered_map<int, int> isTrusted;
        
//         for(unsigned int i = 0; i < trust.size(); i++){
//             whoTrustsWhom[trust[i][0]].push_back(trust[i][1]);
//             isTrusted[trust[i][1]]++;
//         }
        
//         for(int person = 1; person <= n; person++){
//             if(whoTrustsWhom[person].size() == 0 && isTrusted[person] == n - 1) return person;
//         }
        
//         return -1;
//     }
// };



// Space complexity: O(N) - 60.7 MB, less than 81.63% of C++ online submissions
//  Time complexity: O(V + E) - 188 ms, faster than 79.36% of C++ online submissions
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustDegree(n + 1, 0);
        
        for(unsigned int i = 0; i < trust.size(); i++){
            trustDegree[trust[i][0]]--;
            trustDegree[trust[i][1]]++;
        }
        
        for(int person = 1; person <= n; person++){
            if(trustDegree[person] == n - 1) return person;
        }
        
        return -1;
    }
};
