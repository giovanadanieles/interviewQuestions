// Space complexity: O(N * M) - 6.9 MB, less than 31.34% of C++ online submissions
//  Time complexity: O(N * M) -  6 ms, faster than 9.77% of C++ online submissions
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftBound, rightBound, topBound, bottomBound, totalSize;
        vector<int> ans;
        
        if(matrix.size() == 0 || matrix[0].size() == 0) return ans;
        
        leftBound = 0;
        rightBound = matrix[0].size() -1;
        topBound = 0;
        bottomBound = matrix.size() - 1;
        totalSize = matrix.size() * matrix[0].size();
        
        while(ans.size() < totalSize){
            for(int i = leftBound; i <= rightBound && ans.size() < totalSize; i++){
                ans.push_back(matrix[topBound][i]);
            }
            topBound++;
            
            for(int i = topBound; i <= bottomBound && ans.size() < totalSize; i++){
                ans.push_back(matrix[i][rightBound]);
            }
            rightBound--;
            
            for(int i = rightBound; i >= leftBound && ans.size() < totalSize; i--){
                ans.push_back(matrix[bottomBound][i]);
            }
            bottomBound--;
            
            for(int i = bottomBound; i >= topBound && ans.size() < totalSize; i--){
                ans.push_back(matrix[i][leftBound]);
            }
            leftBound++;
        }
        
        return ans;
    }
};
