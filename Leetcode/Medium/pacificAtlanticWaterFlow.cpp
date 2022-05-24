// Ref: https://www.youtube.com/watch?v=s-VkcjHqkGI

// Space complexity: O(M * N) - 34.1 MB, less than 9.17% of C++ online submissions 
//  Time complexity: O(M * N) - 86 ms, faster than 27.44% of C++ online submissions
class Solution {
public:
    unordered_map<size_t, vector<int>> keyToCoord;
    
    inline size_t key(int x, int y) {return (size_t) x << 32 | (unsigned int) y;}
    
    void dfs(vector<vector<int>>& heights, int x, int y, int prevHeight, unordered_set<size_t> &ocean){
        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size()) return;
        else if(heights[x][y] < prevHeight) return;
        else if(ocean.find(key(x, y)) != ocean.end()) return;
        
        ocean.insert(key(x, y));
        keyToCoord[key(x, y)] = {x, y};
        
        dfs(heights, x + 1, y, heights[x][y], ocean);
        dfs(heights, x - 1, y, heights[x][y], ocean);
        dfs(heights, x, y + 1, heights[x][y], ocean);
        dfs(heights, x, y - 1, heights[x][y], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       /*   to which cells can i go to starting at pacific? 
            to which cells can i go to starting at atlantic?
        */
        
        int n = (int)heights.size(), m = (int)heights[0].size();
        unordered_set<size_t> pacific, atlantic;
        vector<vector<int>> ans;
        
        for(int col = 0; col < m; col++){
            // first row, cells reachable by pacific
            dfs(heights, 0, col, heights[0][col], pacific);
            // last row, cells reachable by atlantic
            dfs(heights, n - 1, col, heights[n - 1][col], atlantic);
        }
        
        for(int row = 0; row < n; row++){
            // first col, cells reachable by pacific
            dfs(heights, row, 0, heights[row][0], pacific);
            // last col, cells reachable by atlantic
            dfs(heights, row, m - 1, heights[row][m - 1], atlantic);
        }
        
        for(auto cell = pacific.begin(); cell != pacific.end(); cell++){
            if(atlantic.find(*cell) != atlantic.end()) ans.push_back(keyToCoord[*cell]);
        }
        
        return ans;
    }
};
