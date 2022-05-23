// Ref: https://www.youtube.com/watch?v=gqXU1UyA8pk

// Space complexity: O(26) = O(1) - 7 MB, less than 86.58% of C++ online submissions
//  Time complexity: O(26*N) = O(N) - 27 ms, faster than 28.30% of C++ online submissions
class Solution {
public:
    int getMostFreq(vector<int> &count){
        int mostFreq = 0;
        
        for(unsigned int i = 0; i < count.size(); i++) mostFreq = max(mostFreq, count[i]);
        
        return mostFreq;
    }
    
    int characterReplacement(string s, int k) {
        /* sizeOfWindow - frequencyMostFreq <= k? */
        int left, right, mostFreq, ans = 0;
        vector<int> count(26, 0);
        
        left = right = 0;
        
        while(right < s.size()){
            count[s[right] - 'A']++;
            
            mostFreq = getMostFreq(count);
            
            while(left < right && (right - left + 1 - mostFreq) > k) count[s[left++] - 'A']--;
            
            ans = max(ans, right - left + 1);
            
            right++;
        }
        
        return ans;
    }
};
