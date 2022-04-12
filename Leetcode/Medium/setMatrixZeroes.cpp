// Space complexity: O(M + N) - 13.3 MB, less than 53.72% of C++ online submissions
//  Time complexity: O(N * M) - 21 ms, faster than 44.13% of C++ online submissions
// class Solution {
// public:    
//     void setZeroes(vector<vector<int>>& matrix) {
//         unordered_set<int> zeroRow, zeroCol;
        
//         for(unsigned int row = 0; row < matrix.size(); row++){
//             for(unsigned int col = 0; col < matrix[row].size(); col++){
//                 if(matrix[row][col] == 0) zeroRow.insert(row), zeroCol.insert(col);
//             }
//         }
        
//         for(unsigned int row = 0; row < matrix.size(); row++){
//             for(unsigned int col = 0; col < matrix[row].size(); col++){
//                 if(zeroRow.find(row) != zeroRow.end() || zeroCol.find(col) != zeroCol.end()) 
//                     matrix[row][col] = 0;
//             }
//         }
//     }
// };



// Space complexity: O(1) - 13.2 MB, less than 81.88% of C++ online submissions
//  Time complexity: O(N * M) - 25 ms, faster than 27.03% of C++ online submissions
class Solution {
public:    
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero = false;
        
        for(unsigned int row = 0; row < matrix.size(); row++){
            for(unsigned int col = 0; col < matrix[row].size(); col++){
                if(matrix[row][col] == 0){
                    if(row == 0) isFirstRowZero = true;
                    else matrix[row][0] = 0;
                    
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(unsigned int row = 1; row < matrix.size(); row++){
            if(matrix[row][0] == 0){
                for(unsigned int col = 1; col < matrix[row].size(); col++){
                    matrix[row][col] = 0;
                }
            }
        }
        
        for(unsigned int col = 0; col < matrix[0].size(); col++){
            if(matrix[0][col] == 0){
                for(unsigned int row = 1; row < matrix.size(); row++){
                    matrix[row][col] = 0;
                }
            }
        }
        
        if(isFirstRowZero == true){
            for(unsigned int col = 0; col < matrix[0].size(); col++){
                matrix[0][col] = 0;
            }
        }
    }
};
