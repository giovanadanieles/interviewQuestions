// Space complexity: O(N^2) - less than 58.17% of C++ online submissions
//  Time complexity: O(N^2) - faster than 73.18% of C++ online submissions
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int valuesPerLine, valuesUntilNow = 0;
        vector<int> array;
        vector<vector<int>> reshapedMatrix;
        
        if(mat.size() * mat[0].size() != r * c) return mat;
        
        valuesPerLine = (mat.size() * mat[0].size()) / r;
                        
        for(unsigned int i = 0; i < mat.size(); i++){
            for(unsigned int j = 0; j < mat[i].size(); j++){
                valuesUntilNow++;
                
                array.push_back(mat[i][j]);
                
                if(valuesUntilNow == valuesPerLine){
                    reshapedMatrix.push_back(array);
                    array.clear();
                    valuesUntilNow = 0;
                }
            }
        }
        
        return reshapedMatrix;
    }
};
