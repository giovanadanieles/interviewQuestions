//  Time complexity: O(V + E)

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    stack<int> toBeVisited;
    int visited[100007];
    
    void dfs(int root, vector<vector<int>>& connections){
        int cur;
        
        toBeVisited.push(root);
        
        while(!toBeVisited.empty()){
            cur = toBeVisited.top();
            toBeVisited.pop();
            
            if(visited[cur] == 0){
                visited[cur] = 1;
                
                for(unsigned int i = 0; i < adjList[cur].size(); i++){
                    toBeVisited.push(adjList[cur][i]);
                }
            }
        }
        
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int nEdges = 0, nComponents = 0, redEdges, ans;
        
        memset(visited, 0, sizeof(visited));
        
        // Making adjacency list
        for(int i = 0; i < connections.size(); i++){
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
            
            nEdges++;
        }
        
        // Counting number of components
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                nComponents++;
                
                dfs(i, connections);
            }
        }
        
        // redundantEdges = #edges - ((#nodes - 1) - (#components - 1))
        redEdges = nEdges - ((n - 1) - (nComponents - 1));
        
        if(nEdges < (n - 1) || redEdges < (nComponents - 1)) ans = -1;
        else ans = nComponents - 1;
                
        return ans;
    }
};
