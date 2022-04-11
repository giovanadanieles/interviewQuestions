// Ref: https://www.youtube.com/watch?v=X6RkyPFE6wg

// Space complexity: O(V + E) - 177.8 MB, less than 48.49% of C++ online submissions
//  Time complexity: O(V) - 1134 ms, faster than 29.09% of C++ online submissions
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int curNode;
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int, vector<int>> adjList;
        
        // creating graph
        for(unsigned int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        // search destiny with bfs
        q.push(source);
        
        while(!q.empty()){
            curNode = q.front();
            q.pop();
            
            if(curNode == destination) return true;
            
            visited.insert(curNode);
            
            for(int i = 0; i < adjList[curNode].size(); i++){
                if(visited.find(adjList[curNode][i]) == visited.end()){
                    q.push(adjList[curNode][i]);
                }
            }        
        }
                
        return false;
    }
};
