// Ref: https://cp-algorithms.com/graph/finding-cycle.html
// Space complexity: O(V + E) - 15.3 MB, less than 18.10% of C++ online submissions
//  Time complexity: O(E) - 36 ms, faster than 31.97% of C++ online submissions
class Solution {
public:
    bool findCycle(unordered_map<int, vector<int>> &graph, vector<int> &colors, int curNode){
        colors[curNode] = 1;
        
        for(auto neigh : graph[curNode]){
            if(colors[neigh] == 0 && findCycle(graph, colors, neigh) == true) return true;
            else if(colors[neigh] == 1) return true;
        }
        
        colors[curNode] = 2;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> colors(numCourses, 0);
        unordered_map<int, vector<int>> graph;
        
        if(prerequisites.size() == 0) return true;
        
        for(auto prereq : prerequisites) graph[prereq[0]].push_back(prereq[1]);
        
        for(int n = 0; n < numCourses; n++){
            if(colors[n] == 0 && findCycle(graph, colors, n) == true) return false;
        }
        
        return true;
    }
};
