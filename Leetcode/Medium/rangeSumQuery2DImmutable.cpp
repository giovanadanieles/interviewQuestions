// Ref: https://www.youtube.com/watch?v=CSajkULJ4hk&list=PLif-9qUKVJz9wsfdBreZrx7xRAnsNWXcS&index=6
// Space complexity: O(N*M) - 148.1 MB, less than 21.68% of C++ online submissions
//  Time complexity: O(N*M) - 444 ms, faster than 88.33% of C++ online submissions
class NumMatrix {
public:
    vector<vector<int>> prefixMatrix;
    
    // Time: O(N*M)
    NumMatrix(vector<vector<int>>& matrix) : prefixMatrix(matrix.size(), vector<int>(matrix[0].size())){
        /*
            Para calcular P[i, j], temos (principio da inclusao e exclusao):
                P[i, j] = M[i, j] + P[i - 1, j] + P[i, j - 1] - P[i - 1, j - 1]
        */
                
        for(int row = 0; row < (int)matrix.size(); row++){
            for(int col = 0; col < (int)matrix[0].size(); col++){
                prefixMatrix[row][col] = matrix[row][col];
                
                if(row - 1 >= 0) prefixMatrix[row][col] += prefixMatrix[row - 1][col];
                if(col - 1 >= 0) prefixMatrix[row][col] += prefixMatrix[row][col - 1];
                if(row - 1 >= 0 && col - 1 >= 0) prefixMatrix[row][col] -= prefixMatrix[row - 1][col - 1];
            }
        }
    }
    
    // Time: O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum;
        
        sum = prefixMatrix[row2][col2];
        
        if(col1 - 1 >= 0) sum -= prefixMatrix[row2][col1 - 1];
        if(row1 - 1 >= 0) sum -= prefixMatrix[row1 - 1][col2];
        if(row1 - 1 >= 0 && col1 - 1 >= 0) sum += prefixMatrix[row1 - 1][col1 - 1];
        
        return sum;
    }
};



/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
