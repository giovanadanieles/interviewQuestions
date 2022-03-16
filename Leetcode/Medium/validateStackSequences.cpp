// Space complexity: O(N) - 15.4 MB, less than 59.16% of C++ online submissions
//  Time complexity: O(N) - 18 ms, faster than 26.06% of C++ online submissions
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        
        for(unsigned int pushPointer = 0, popPointer = 0; pushPointer < pushed.size(); pushPointer++){
            s.push(pushed[pushPointer]);
                        
            while(!s.empty() && popPointer < popped.size() && s.top() == popped[popPointer]){
                s.pop();
                popPointer++;
            }
        }
        
        if(!s.empty()) return false;
        else return true;
    }
};
