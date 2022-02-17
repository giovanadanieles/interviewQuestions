// Space complexity: O(1) - less than 52.18% of C++ online submissions
//  Time complexity: O(N) - faster than 77.93% of C++ online submissions
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unsigned int index, left, right, mid;
                
        for(index = 0; index < matrix.size(); index++){
            if(matrix[index][0] > target) break;
        }
                
        if(index == 0) return false;
        
        index--;
                
        left = 0;
        right = matrix[index].size() - 1;
        
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(matrix[index][mid] < target) left = mid + 1;
            else right = mid;
        }
        
        if(matrix[index][left] == target) return true;
        else return false;
    }
};
