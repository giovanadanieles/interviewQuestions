// Space complexity: O(max(2N, K)) - 10.4 MB, less than 91.37% of C++ online submissions
//  Time complexity: O(N ^ 2) - 4 ms, faster than 99.88% of C++ online submissions
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int numOfSoldiers;
        vector<int> ans;
        vector<pair<int, int>> weakest;
        
        for(unsigned int row = 0; row < mat.size(); row++){
            numOfSoldiers = 0;
            
            for(unsigned int column = 0; column < mat[row].size(); column++){
                numOfSoldiers += mat[row][column];
            }
            
            weakest.push_back({numOfSoldiers, row});
        }
        
        sort(weakest.begin(), weakest.end());
        
        for(unsigned int i = 0; i < k; i++){
            ans.push_back(weakest[i].second);
        }
        
        return ans;
    }
};
