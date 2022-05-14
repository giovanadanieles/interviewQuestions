// Ref: https://www.youtube.com/watch?v=EaphyqKU4PQ

// Space complexity: O(V+E) - 44.8 MB, less than 16.43% of C++ online submissions
//  Time complexity: O((V+E)logV) - 141 ms, faster than 70.10% of C++ online submissions
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int delayTime = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, vector<pair<int, int>>> adjList;
        
        for(auto neigh : times) adjList[neigh[0]].push_back({neigh[1], neigh[2]});
        
        minHeap.push({0, k});
        
        while(!minHeap.empty()){
            auto curNode = minHeap.top();
            minHeap.pop();
            
            if(visited.find(curNode.second) == visited.end()){
                visited.insert(curNode.second);
                delayTime = max(delayTime, curNode.first);
                
                for(auto neigh : adjList[curNode.second]){
                    if(visited.find(neigh.first) == visited.end()) 
                        minHeap.push({curNode.first + neigh.second, neigh.first});
                }
            }
        }
        
        return visited.size() == (unsigned int) n ? delayTime : -1;
    }
};
