// Ref: https://www.youtube.com/watch?v=P6RZZMu_maU

// Space complexity: O(N) - 30.9 MB, less than 61.27% of C++ online submissions
//  Time complexity: O(N) - 548 ms, faster than 29.45% of C++ online submissions
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0, curElem, curSeqSize;
        unordered_set<int> numbers;
        
        for(unsigned int i = 0; i < nums.size(); i++) numbers.insert(nums[i]);
        
        for(unsigned int  i = 0; i < nums.size(); i++){
            // if the cur number is the beginning of a sequence, then we have to analyze it
            if(numbers.find(nums[i] - 1) == numbers.end()){
                curSeqSize = 1;
                curElem = nums[i] + 1;
                
                while(numbers.find(curElem) != numbers.end()) curSeqSize++, curElem++;
                
                longestSeq = max(longestSeq, curSeqSize);
            }
        }
        
        return longestSeq;
    }
};
