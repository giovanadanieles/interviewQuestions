// Space complexity: O(1) - 111.7 MB, less than 29.27% of C++ online submissions
//  Time complexity: O(2N) = O(N) - 187 ms, faster than 50.45% of C++ online submissions
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int target1, target2, missingTop, missingBottom;
        
        target1 = tops[0];
        target2 = bottoms[0];
        
        missingTop = 0, missingBottom = 0;
        for(unsigned int i = 0; i < tops.size(); i++){
            if(tops[i] != target1 && bottoms[i] != target1) break;
            
            if(tops[i] != target1) missingTop++;
            if(bottoms[i] != target1) missingBottom++; 
            
            if(i == tops.size() - 1) return min(missingTop, missingBottom);
        }
        
        missingTop = 0, missingBottom = 0;
        for(unsigned int i = 0; i < tops.size(); i++){
            if(tops[i] != target2 && bottoms[i] != target2) break;
            
            if(tops[i] != target2) missingTop++;
            if(bottoms[i] != target2) missingBottom++; 
            
            if(i == tops.size() - 1) return min(missingTop, missingBottom);
        }
        
        return -1;
    }
};
