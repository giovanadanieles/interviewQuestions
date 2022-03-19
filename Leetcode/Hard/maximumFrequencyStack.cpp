// Ref: https://www.youtube.com/watch?v=Z6idIicFDOE



// Space: 80.5 MB, less than 81.70% of C++ online submissions
//  Time: 317 ms, faster than 40.77% of C++ online submissions
class FreqStack {
public:  
    int maxCount;
    unordered_map<int, int> varCount;
    unordered_map<int, vector<int>> stacks;
    
    FreqStack() {}
    
    // Time complexity: O(1)
    void push(int val) {
       int valCount = 1 + varCount[val];
       varCount[val] = valCount;
        
        if(valCount > maxCount){
            maxCount = varCount[val];
            vector<int> newVec;
            
            //add a new stack to the stack of stacks
            stacks.insert({valCount, newVec});
        }
        
        stacks[valCount].push_back(val);
    }
    
    // Time complexity: O(1)
    int pop() {
        int ans = stacks[maxCount].back();
        stacks[maxCount].pop_back();
            
        varCount[ans]--;
        
        if(stacks[maxCount].empty()) maxCount--;
        
        return ans;
    }
};



/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
