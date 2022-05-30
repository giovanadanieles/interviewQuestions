// Space complexity: O(N^2) - 15.7 MB, less than 5.22% of C++ online submissions
//  Time complexity: O(N^2) - 53 ms, faster than 13.63% of C++ online submissions
// class Solution {
// public:
//     void dfs(unordered_map<int, vector<int>> &adjList, unordered_set<int> &visited, int curNode){
//         if(visited.find(curNode) != visited.end()) return;
        
//         visited.insert(curNode);
        
//         for(auto neigh : adjList[curNode]){
//             dfs(adjList, visited, neigh);
//         }
//     }
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int ans = 0;
//         unordered_set<int> visited;
//         unordered_map<int, vector<int>> adjList;
        
//         for(int row = 0; row < isConnected.size(); row++){
//             for(int col = 0; col < isConnected[0].size(); col++){
//                 if(row != col && isConnected[row][col] == 1){
//                     adjList[row].push_back(col);
//                     adjList[col].push_back(row);
//                 }
//             }
//         }
        
//         for(int province = 0; province < isConnected.size(); province++){
//             if(visited.find(province) == visited.end()){
//                 dfs(adjList, visited, province);
//                 ans++;
//             }
//         }
        
//         return ans;
//     }
// };



// Space complexity: O(N) - 13.7 MB, less than 88.27% of C++ online submissions
//  Time complexity: O(N*N) - 32 ms, faster than 53.29% of C++ online submissions
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int curProvince){
        visited[curProvince] = true;
        
        for(int province = 0; province < isConnected.size(); province++){
            if(visited[province] == false && isConnected[curProvince][province] == 1){
                dfs(isConnected, visited, province);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        
        for(int province = 0; province < isConnected.size(); province++){
            if(visited[province] == false){
                dfs(isConnected, visited, province);
                ans++;
            }
        }
        
        return ans;
    }
};
