// Space complexity: O(N^2) - less than 91.66% of C++ online submissions
//  Time complexity: O(N^2) - faster than 100.00% of C++ online submissions
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
       for(int i = 0; i < numRows; i++){
           vector<int> line(i + 1, 1);
           
           for(int j = 1; j < i; j++){
               line[j] = ans[i - 1][j] + ans[i - 1][j - 1];
           }
           
           ans.push_back(line);
       }
        
        return ans;
    }
};
