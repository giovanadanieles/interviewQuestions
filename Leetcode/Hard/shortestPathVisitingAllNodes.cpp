// Memory Usage: 18.2 MB, less than 41.42% of C++ online submissions
// Runtime: 147 ms, faster than 36.80% of C++ online submissions
class Solution {
public:
    int solve(vector<vector<int>>& graph){
        int size, all, nodeVal, distance, mask;
        set<pair<int, int>> visited; 
        //     nodeVal  distance mask
        queue<pair<int, pair<int, int>>> q;
        
        size = (int)graph.size();
        all = (1 << size) - 1; // size = 3 --> 1000 - 1 = 1111
        
        for(int i = 0; i < size; i++){
            mask = (1 << i);
            
            // initializing queue for bfs
            q.push(make_pair(i, make_pair(0, mask)));
            visited.insert(make_pair(i, mask));
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            nodeVal = node.first;
            distance = node.second.first;
            mask = node.second.second;
            
            //vising all neighbours of nodeVal
            for(auto neigh : graph[nodeVal]){
                int newMask = (mask | (1 << neigh)); // p.e. 0 and 1 = (0001 | 0010) = (0011)
                
                if(newMask == all) return distance + 1;
                else if(visited.count(make_pair(neigh, newMask))) continue;
                else{
                    visited.insert(make_pair(neigh, newMask));
                    q.push(make_pair(neigh, make_pair(distance + 1, newMask)));
                }
            }
        }
        
        return 0;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) return 0;
        
        return solve(graph);
    }
};
