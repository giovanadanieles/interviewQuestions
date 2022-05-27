// Ref: https://www.youtube.com/watch?v=sQnIdYxxmeE

// KAHN'S ALGORITHM FOR TOPOLOGICAL SORTING
// Space complexity: O(V+E) - 16.5 MB, less than 7.67% of C++ online submissions
//  Time complexity: O(V+E) - 28 ms, faster than 58.44% of C++ online submissions
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adjList, vector<bool> &visited, unordered_set<int> &cycleTracker, 
             stack<int> &invTopologicalSort, int curNode, bool &isCycle){
        
        visited[curNode] = true;
        cycleTracker.insert(curNode);
        
        for(auto neigh : adjList[curNode]){
            if(cycleTracker.find(neigh) != cycleTracker.end()) isCycle = true;
            if(visited[neigh] == false) dfs(adjList, visited, cycleTracker, invTopologicalSort, neigh, isCycle);
        }
        
        cycleTracker.erase(curNode);
        invTopologicalSort.push(curNode);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
                Two tracking mechanisms: one visited set for the topological sort logic,
            one tracker set for cycles.
        */
        
        bool isCycle = false;
        vector<bool> visited(numCourses, false);
        vector<int> ans;
        stack<int> invTopologicalSort;
        unordered_set<int> cycleTracker;
        unordered_map<int, vector<int>> adjList;
        
        for(auto prereq : prerequisites) adjList[prereq[1]].push_back(prereq[0]);
        
        for(int node = 0; node < numCourses; node++){
            if(visited[node] == false) dfs(adjList, visited, cycleTracker, invTopologicalSort, node, isCycle);
            if(isCycle == true) return ans;
        }
        
        while(!invTopologicalSort.empty()){
            ans.push_back(invTopologicalSort.top());
            invTopologicalSort.pop();
        }
        
        return ans;
    }
};
