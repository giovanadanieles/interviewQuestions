// Space complexity: O(N*M) - 10.5 MB, less than 95.40% of C++ online submissions
//  Time complexity: O(N*M) - 15 ms, faster than 65.95% of C++ online submissions
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {        
        vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
        
        for(unsigned int row = 0; row < matrix.size(); row++){
            for(unsigned int col = 0; col < matrix[0].size(); col++){
                transposed[col][row] = matrix[row][col];
            }
        }
        
        return transposed;
    }
};
