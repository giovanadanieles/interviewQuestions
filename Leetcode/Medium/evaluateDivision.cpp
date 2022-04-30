// Space complexity: O(V + E) - beats 74.57 % of cpp submissions
//  Time complexity: O(V + E) - beats 26.64 % of cpp submissions
class Solution {
public:    
    int getIndex(int &curIndex, string s, unordered_map<string, int> &strToInt){
        if(strToInt.find(s) == strToInt.end())  strToInt[s] = curIndex++;
        
        return strToInt[s];
    }
    
    double evaluateDFS(vector<vector<double>> &graph, int x, int y){
        pair<int, double> cur;
        vector<bool> visited(graph.size(), false);
        stack<pair<int, double>> stck;
        
        stck.push({x, 1.0});
        visited[x] = true;
        
        while(!stck.empty()){
            cur = stck.top();
            stck.pop();
            
            if(cur.first == y) return cur.second;
            
            for(int neigh = 0; neigh < graph[cur.first].size(); neigh++){
                if(graph[cur.first][neigh] != -1.0 && visited[neigh] == false){
                    stck.push({neigh, cur.second * graph[cur.first][neigh]});
                    visited[neigh] = true;
                }
            }
        }
        
        return -1.0;
    }
     
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int curIndex = 0, x, y;
        vector<double> ans;
        unordered_map<string, int> strToInt;
        vector<vector<double>> graph(equations.size() * 2, vector<double>(equations.size() * 2, -1.0)); 
        
        for(unsigned int i = 0; i < equations.size(); i++){
            x = getIndex(curIndex, equations[i][0], strToInt);
            y = getIndex(curIndex, equations[i][1], strToInt);
            
            graph[x][y] = values[i];
            graph[y][x] = 1 / values[i];
        }
        
        for(unsigned int i = 0; i < queries.size(); i++){
            if(strToInt.find(queries[i][0]) == strToInt.end() ||
                    strToInt.find(queries[i][1]) == strToInt.end()) ans.push_back(-1.0);
            else if(queries[i][0] == queries[i][1]) ans.push_back(1.0);
            else{
                x = getIndex(curIndex, queries[i][0], strToInt);
                y = getIndex(curIndex, queries[i][1], strToInt);
                
                ans.push_back(evaluateDFS(graph, x, y));
            }
        }
        
        return ans;
    }
};
