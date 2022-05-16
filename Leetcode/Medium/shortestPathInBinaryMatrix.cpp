// Space complexity: O(V+E) - 131.3 MB, less than 5.07% of C++ online submissions
//  Time complexity: O(N^2) - 801 ms, faster than 5.01% of C++ online submissions
// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int cols = (int)grid[0].size();
//         int nodeIndex = 1, goal = grid.size() * grid[0].size(), ans = -1;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
//         vector<bool> visited(goal + 1, false);
//         vector<vector<int>> directions = {{-1,-1,-cols-1}, {-1,0,-cols}, {-1,1,-cols+1},
//                                           {0, -1,-1}, {0, 1, 1},
//                                           {1, -1, cols-1}, {1, 0, cols}, {1, 1, cols+1}};
//         unordered_map<int, vector<int>> adjList;
        
//         // creating adj list
//         for(int row = 0; row < grid.size(); row++){
//             for(int col = 0;  col < grid[0].size(); col++){
//                 if(grid[row][col] == 0){
//                     for(auto direction : directions){
//                         if(row + direction[0] >= 0 && row + direction[0] < grid.size() &&
//                            col + direction[1] >= 0 && col + direction[1] < grid[0].size() &&
//                            grid[row + direction[0]][col + direction[1]] == 0){
//                             adjList[nodeIndex].push_back(nodeIndex + direction[2]);
//                         }
//                     }
//                 }
                
//                 nodeIndex++;
//             }
//         }
        
//         // dijkstra
//         minHeap.push({1, 1});
        
//         while(!minHeap.empty()){
//             auto curNode = minHeap.top();
//             minHeap.pop();
            
//             if(curNode.second == goal) return curNode.first;
            
//             if(visited[curNode.second] == false){
//                 visited[curNode.second] = true;
                
//                 for(auto neigh : adjList[curNode.second]){
//                     if(visited[neigh] == false) minHeap.push({1 + curNode.first, neigh});
//                 }    
//             }
//         }
        
//         return -1;
//     }
// };



// Space complexity: O(V) - 86.9 MB, less than 6.49% of C++ online submissions
//  Time complexity: O(V + E) - 491 ms, faster than 9.85% of C++ online submissions
// class Solution {
// public:
//     inline size_t key(int x, int y) {return (size_t) x << 32 | (unsigned int) y;}
    
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid){
//         unordered_set<size_t> visited;
//         queue<pair<pair<int, int>, int>> q;
//         vector<vector<int>> directions = {{-1,-1}, {-1,0}, {-1,1},
//                                           {0, -1}, {0, 1},
//                                           {1, -1}, {1, 0}, {1, 1}};
        
//         if(grid[0][0] != 0) return -1;
        
//         q.push({{0,0},1});
//         visited.insert(key(0,0));
        
//         while(!q.empty()){
//             auto curNode = q.front();
//             q.pop();
            
//             if(curNode.first.first == (int)grid.size() - 1 && 
//                curNode.first.second == (int)grid[0].size() - 1) return curNode.second;

//             for(auto direction : directions){
//                 int x = curNode.first.first + direction[0], y = curNode.first.second + direction[1];

//                  if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0){
//                      if(visited.find(key(x, y)) == visited.end()){
//                          q.push({{x,y},curNode.second + 1});
//                          visited.insert(key(x, y));
//                      }
//                  }
//             }
//         }
        
//         return -1;
//     }
// };



// Space complexity: O(V) - 20.2 MB, less than 59.11% of C++ online submissions
//  Time complexity: O(V+E) - 72 ms, faster than 76.79% of C++ online submissions
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        queue<pair<pair<int, int>, int>> q;
        int directions[8][2] = {{-1,-1}, {-1,0}, {-1,1},
                                          {0, -1}, {0, 1},
                                          {1, -1}, {1, 0}, {1, 1}};
        
        if(grid[0][0] != 0) return -1;
        else grid[0][0] = 1;
        
        q.push({{0,0},1});
        
        while(!q.empty()){
            auto curNode = q.front();
            q.pop();
            
            if(curNode.first.first == (int)grid.size() - 1 && 
               curNode.first.second == (int)grid[0].size() - 1) return curNode.second;

            for (auto const& direction : directions){
                int x = curNode.first.first + direction[0], y = curNode.first.second + direction[1];

                 if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0){
                     q.push({{x,y},curNode.second + 1});
                     grid[x][y] = 1;
                 }
            }
        }
        
        return -1;
    }
};
