// Space complexity: O(1) - 67.4 MB, less than 55.60% of C++ online submissions
//  Time complexity: O(1) - faster than 84.79% of C++ online submissions
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int firstNeigh, secNeigh;
        
        firstNeigh = edges[0][0];
        secNeigh = edges[0][1];
        
        if(edges[1][0] == firstNeigh || edges[1][1] == firstNeigh) return firstNeigh;
        else return secNeigh;
    }
};
