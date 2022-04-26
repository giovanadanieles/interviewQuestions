// Ref 1: https://www.youtube.com/watch?v=4ZlRH0eK-qQ
// Ref 2: https://www.youtube.com/watch?v=f7JOBJIC-NA

// Space complexity: O(V ^2) - 130.8 MB, less than 22.72% of C++ online submissions
//  Time complexity: O(V^2 log V) - 445 ms, faster than 62.42% of C++ online submissions
class Solution {
public:
    int manhattanDistance(vector<int> &a, vector<int> &b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
        *       MINIMUM COST SPANNING TREE
        *
        *
        *   -> Spanning tree is a subgraph of a graph, having all vertices but
        *  only |V| - 1 edges;
        *
        *   -> The number of possible spanning trees is given by:
        *           |E|_{C_{|V| - 1}} - number of cycles
        *
        *   -> If disconnected components exists, there's no spanning tree.
        *
        *   -> There are two greedy algorithms to find the minimum cost spanning
        *  tree: Kruskal's and Prim's.
        *
        *   -> For Prim's algorithm we start selecting the edge with the small weigth and
        *  then always getting the smallest connected one.
        *       -> Its complexity is O(E log V) or O(V * E).
        *
        *   -> For Kruskal's algorithm we always select the edge with minimum cost, except
        *  in the cases where, if selected, there'll be a cycle on the spanning tree (in 
        *  this case we just ignore this edge and move on).
        *       -> Using minheap, its complexity is O(E log V), otherwise O(V * E).
        *       -> Kruskal's may offer a spanning tree for disconnected graphs.
        *
        *
        *   -> FOR A GIVEN GRAPH, THERE'S ONLY ONE MINIMUM COST VALUE FROM SPANNING TREES.
        */
        
        int numOfVertices, distance, minCost = 0;
        pair<int, int> top;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> frontier;
        vector<pair<int, int>> adjList[points.size()];
        
        numOfVertices = points.size();
        
        for(int i = 0; i < numOfVertices; i++){            
            for(int j = i + 1; j < numOfVertices; j++){
                distance = manhattanDistance(points[i], points[j]);
                
                adjList[i].push_back({distance, j});
                adjList[j].push_back({distance, i});
            }
        }
        
        // Prim's Algorithm
        frontier.push({0, 0});
        
        while(visited.size() < numOfVertices){
            top = frontier.top();
            frontier.pop();
            
            if(visited.find(top.second) != visited.end()) continue;
            
            minCost += top.first;
            visited.insert(top.second);
            
            for(auto neigh : adjList[top.second]){
                if(visited.find(neigh.second) == visited.end()){
                    frontier.push(neigh);
                }
            }
        }
        
        return minCost;
    }
};
