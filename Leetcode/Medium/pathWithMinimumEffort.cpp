// Ref: https://www.youtube.com/watch?v=FabSLaGu0NI

// Space complexity: O((M*N)log(M*N)) = O(E log E) - 52.8 MB, less than 21.36% of C++ online submissions
//  Time complexity: O(M*N) = O(E) - 363 ms, faster than 45.39% of C++ online submissions
class Solution {
public:
    struct effortRowCol{
        int effort, row, col;
        
        effortRowCol(int e, int r, int c) : effort(e), row(r), col(c) {}
    };
    
    struct compareEffort{
        bool operator()(effortRowCol *e1, effortRowCol *e2){
            return e1->effort > e2->effort;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int newRow, newCol, newEffort;
        effortRowCol *cur;
        priority_queue<effortRowCol*, vector<effortRowCol*>, compareEffort> pq;
        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>> efforts(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        
        pq.push(new effortRowCol(0, 0, 0));
        
        while(!pq.empty()){
            cur = pq.top();
            pq.pop();
            
            if(cur->effort > efforts[cur->row][cur->col]) continue;
            if(cur->row == heights.size() - 1 && cur->col == heights[0].size() - 1) return cur->effort;
            
            for(vector<int> dir : directions){
                newRow = cur->row + dir[0];
                newCol = cur->col + dir[1];
                
                if(newRow < heights.size() && newRow >= 0 && newCol < heights[0].size() && newCol >= 0){
                    newEffort = max(cur->effort, abs(heights[cur->row][cur->col] - heights[newRow][newCol]));
                    
                    if(newEffort < efforts[newRow][newCol]){
                        efforts[newRow][newCol] = newEffort;
                        pq.push(new effortRowCol(newEffort, newRow, newCol));
                    }
                }
            }
        }
        
        return -1;
    }
};
