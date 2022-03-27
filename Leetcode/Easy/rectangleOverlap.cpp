// Space complexity: O(1) - 7.8 MB, less than 19.69% of C++ online submissions
//  Time complexity: O(1) - 0 ms, faster than 100.00% of C++ online submissions
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] >= rec2[2] || rec2[0] >= rec1[2]) return false;
        if (rec1[1] >= rec2[3] || rec2[1] >= rec1[3]) return false;
        
        return true;
    }
};
