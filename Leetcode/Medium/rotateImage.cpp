// Space complexity: O(N) - 7.2 MB, less than 33.07% of C++ online submissions
//  Time complexity: O(N ^ 2) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int leftBound, rightBound, topBound, bottomBound, size, numVals = 0, total;
//         queue<int> nextNumbers;
        
//         size = matrix.size();
//         total = size * size;
        
//         leftBound = topBound = 0;
//         rightBound = bottomBound = size - 1;
        
//         while(numVals < total){
//             for(int col = leftBound; col <= rightBound - 1; col++){
//                 nextNumbers.push(matrix[topBound][col]);
//             }
            
//             for(int row = topBound; row <= bottomBound && numVals < total; row++){
//                 nextNumbers.push(matrix[row][rightBound]);
                
//                 matrix[row][rightBound] = nextNumbers.front();
//                 nextNumbers.pop();
                
//                 numVals++;
//             }
//             rightBound--;
            
//             for(int col = rightBound; col >= leftBound && numVals < total; col--){
//                 nextNumbers.push(matrix[bottomBound][col]);
                
//                 matrix[bottomBound][col] = nextNumbers.front();
//                 nextNumbers.pop();
                
//                 numVals++;
//             }
//             bottomBound--;
            
//             for(int row = bottomBound; row >= topBound && numVals < total; row--){
//                 if(row != topBound) nextNumbers.push(matrix[row][leftBound]);
                
//                 matrix[row][leftBound] = nextNumbers.front();
//                 nextNumbers.pop();
                
//                 numVals++;
//             }
//             leftBound++;
            
//             for(int col = leftBound; col <= rightBound && numVals < total; col++){
//                 matrix[topBound][col] = nextNumbers.front();
//                 nextNumbers.pop();
                
//                 numVals++;
//             }
//             topBound++;   
//         } 
//     }
// };



// Space complexity: O(1) - 7.1 MB, less than 73.70% of C++ online submissions
//  Time complexity: O(N ^ 2) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(unsigned int row = 0; row < matrix.size(); row++){
            for(unsigned int col = row + 1; col < matrix[row].size(); col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
    
    void reflect(vector<vector<int>>& matrix){
        unsigned int leftBound, rightBound;
        
        for(unsigned int row = 0; row < matrix.size(); row++){
            leftBound = 0, rightBound = matrix[row].size() - 1;
            
            while(leftBound < rightBound){
                swap(matrix[row][leftBound], matrix[row][rightBound]);
                
                leftBound++, rightBound--;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix){
        transpose(matrix);
        reflect(matrix);
    }
};
