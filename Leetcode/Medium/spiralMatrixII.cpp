// Space complexity: O(N * 2) -  6.5 MB, less than 64.04% of C++ online submissions
//  Time complexity: O(N * 2) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left, right, top, bottom, totalSize, count = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        
        left = 0;
        right = n -1;
        top = 0;
        bottom = n - 1;
        totalSize = n * n;
        
        while(left <= right && top <= bottom){
            for(int i = left; i <= right && count <= totalSize; i++){
                matrix[left][i] = count;
                count++;
            }
            top++;
            
            for(int i = top; i <= bottom && count <= totalSize; i++){
                matrix[i][right] = count;
                count++;
            }
            right--;
            
            for(int i = right; i >= left && count <= totalSize; i--){
                matrix[bottom][i] = count;
                count++;
            }
            bottom--;
            
            for(int i = bottom; i >= top && count <= totalSize; i--){
                matrix[i][left] = count;
                count++;
            }
            left++;
        }
        
        return matrix;
    }
};
