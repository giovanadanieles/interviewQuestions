// Ref: https://www.youtube.com/watch?v=3jvWodd7ht0

// Space complexity: O(N*2^N) - 57.6 MB, less than 50.44% of C++ online submissions
//  Time complexity: O(N) - 178 ms, faster than 48.94% of C++ online submissions
class Solution {
public:
    bool isPalindrome(string s, int left, int right){  
        while(left < right){
            if(s[left] != s[right]) return false;
            left++, right--;
        }
        
        return true;
    }
    
    void backtracking(vector<vector<string>> &partitions, vector<string> &curPartition, string s, int curIndex){
       /*                                  aab
        *                       a          aa          aab
        *                   a      ab   b           
        *               b
        *
        *   First branch: a is palindrome, a is palindrome, b is palindrome; that's a valid way (V);
        *   Sec branc: a is a palindrome, ab is not; that's not a valid way (X);
        *   Third branch: aa is palindrome, b is palindrome; that's a valid way (V);
        *   Fourth branch: aab is not a valid palindrome; that's not a valid way (X).
        */
        if(curIndex == (int)s.size()){
            partitions.push_back(curPartition);
            return;
        }
        
        for(int i = curIndex; i < (int)s.size(); i++){
            if(isPalindrome(s, curIndex, i)){
                curPartition.push_back(s.substr(curIndex, i - curIndex + 1));
                backtracking(partitions, curPartition, s, i + 1);
                curPartition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curPartition;
        vector<vector<string>> partitions; 
        
        backtracking(partitions, curPartition, s, 0);
        
        return partitions;
    }
};
