// Space complexity: O(V) - 13.5 MB, less thans 57.46 % of C++ online submissions
//  Time complexity: O((V+E)logE) - 22 ms, faster than 89.41 % of C++ online submissions
// class Solution {
// public:    
//     int find_(int x, vector<int> &parents){
//         if(x != parents[x]){
//             parents[x] = find_(parents[x], parents);
//         }
        
//         return parents[x];
//     }
    
//     void union_(int x, int y, vector<int> &parents){
//         int xParent, yParent;
        
//         xParent = find_(x, parents);
//         yParent = find_(y, parents);
        
//         if(xParent != yParent) parents[yParent] = xParent;
//     }

//     bool isBipartite(vector<vector<int>>& graph){
//         vector<int> parents;
        
//         for(unsigned int i = 0; i < graph.size(); i++) parents.push_back(i);
        
//         for(unsigned int i = 0; i < graph.size(); i++){
//             for(int neigh : graph[i]){
//                 if(find_(neigh, parents) == find_(i, parents)) return false;
//                 else union_(graph[i][0], neigh, parents);
//             }
//         }
        
//         return true;
//     }
// };



// Space complexity: O(V) - 13.8 MB, less than 29.29% of C++ online submissions
//  Time complexity: O(V + E) - 50 ms, faster than 17.06% of C++ online submissions 
class Solution {
public:  
    bool isBipartite(vector<vector<int>>& graph){
        int cur;
        vector<int> color(graph.size(), 0);
        vector<bool> visited(graph.size(), false);
        stack<int> stck;
        
        for(unsigned int i = 0; i < graph.size(); i++){
            if(visited[i] == false){
                stck.push(i);
                color[i] = 1;
                
                while(!stck.empty()){
                    cur = stck.top();
                    stck.pop();

                    for(unsigned int i = 0; i < graph[cur].size(); i++){
                        if(color[graph[cur][i]] == color[cur]) return false;
                        else if(visited[graph[cur][i]] == false){
                            if(color[graph[cur][i]] == 0) color[graph[cur][i]] = color[cur] * (-1);
                            stck.push(graph[cur][i]);
                        }
                    }

                    visited[cur] = true;
                }
            }
        }
        
        return true;
    }
};
