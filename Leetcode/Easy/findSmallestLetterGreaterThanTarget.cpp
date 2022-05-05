// Space complexity: O(1) - 15.7 MB, less than 91.32% of C++ online submissions
//  Time complexity: O(logN) - 17 ms, faster than 68.69% of C++ online submissions
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left, right, middle;
        
        left = 0, right = letters.size() - 1;
        while(left < right){
            middle = left + (right - left) / 2;
            
            if(letters[middle] > target) right = middle;
            else left = middle + 1;
        }
        
        if(letters[left] <= target) return letters[(left + 1) % letters.size()];
        else return letters[left];
    }
};
