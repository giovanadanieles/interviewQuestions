// Space complexity: O(N) - 14 MB, less than 42.90% of C++ online submissions
//  Time complexity: O(ElogV) - 46 ms, faster than 55.23% of C++ online submissions
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int visited[101];
        unordered_map<int, vector<pair<int, int>>> adjList;
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, 
                       greater<pair<pair<int, int>, int>>> costStopsDest;
        
        for(auto flight : flights){
            adjList[flight[0]].push_back({flight[1], flight[2]});            
        }
        
        fill_n(visited, 101, INT_MAX);
        
        if(adjList.find(src) == adjList.end()) return -1;
        
        costStopsDest.push({{0, 0}, src});
                        
        while(!costStopsDest.empty()){
            auto [curCost, curStops] = costStopsDest.top().first;
            auto curDst = costStopsDest.top().second;
                        
            costStopsDest.pop(); 
            
            if(curDst == dst) return curCost;

            if(curStops > k) continue;
            
            if(curStops >= visited[curDst]) continue;
            
            visited[curDst] = curStops;
            
            for(auto neigh : adjList[curDst]){
                costStopsDest.push({{curCost + neigh.second, curStops + 1}, neigh.first});
            }
        }
        
        return -1;
    }
};
