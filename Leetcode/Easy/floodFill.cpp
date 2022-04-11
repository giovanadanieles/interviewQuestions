// Space complexity: O(N) - 14.1 MB, less than 50.77% of C++ online submissions
//  Time complexity: O(N) - 11 ms, faster than 69.21% of C++ online submissions
class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor){
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) return;
        if(image[x][y] != oldColor || image[x][y] == newColor) return;
        
        int color = image[x][y];
        image[x][y] = newColor;
        
        dfs(image, x + 1, y, color, newColor);
        dfs(image, x - 1, y, color, newColor);
        dfs(image, x, y + 1, color, newColor);
        dfs(image, x, y - 1, color, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};
