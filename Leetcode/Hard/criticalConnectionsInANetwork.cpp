// Ref 1: https://www.youtube.com/watch?v=RYaakWv5m6o
// Ref 2: https://leetcode.com/problems/critical-connections-in-a-network/discuss/410345/Python-(98-Time-100-Memory)-clean-solution-with-explanaions-for-confused-people-like-me

// TARJAN'S ALGORITHM
// Space complexity: O(V) - 196.6 MB, less than 19.92% of C++ online submissions
//  Time complexity: O(V + E) - 1154 ms, faster than 20.75% of C++ online submissions
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &lowestRank, int curNode,
             int prevNode, int curRank, vector<vector<int>> &bridges){
        
        visited[curNode] = true;
        lowestRank[curNode] = curRank;
        
        for(auto neigh : graph[curNode]){
            if(neigh == prevNode) continue;
            
            if(visited[neigh] == false) dfs(graph, visited, lowestRank, neigh, curNode, curRank + 1, bridges);
            
            lowestRank[curNode] = min(lowestRank[curNode], lowestRank[neigh]);
            
            if(curRank < lowestRank[neigh]) bridges.push_back({curNode, neigh});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        /*
            -> Brute force approach: remove each connection and traverse the graph using dfs,
            couting the number of reachable nodes; if num of reachable nodes != total num of nodes,
            the graph was divided into two components, thus the removed connection is a critical one.
                |-> Time complexity: O(E * (V+E))
        */
        
        vector<vector<int>> bridges;
        unordered_map<int, vector<int>> adjList;
        vector<int> lowestRank(connections.size() + 1);
        vector<bool> visited(connections.size(), false);
        
        for(auto neigh : connections){
            adjList[neigh[0]].push_back(neigh[1]);
            adjList[neigh[1]].push_back(neigh[0]);
        }
        
        dfs(adjList, visited, lowestRank, 0, -1, 0, bridges);
        
        return bridges;
    }
};
