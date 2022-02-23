// Runtime: 0 ms, faster than 100.00% of C++ online submissions
// Memory Usage: 7 MB, less than 49.74% of C++ online submissions

class MyQueue {
public:
    // Space complexity: O(N)
    stack<int> pushStack, popStack;
    MyQueue() {
        
    }
    
    // Space complexity: O(1)
    //  Time complexity: O(1)
    void push(int x) {
        pushStack.push(x);
    }
    
    // Space complexity: O(1)
    //  Time complexity: O(2N) = O(N)
    int pop() {
        int value;
        
        while(!pushStack.empty()){
            popStack.push(pushStack.top());
            pushStack.pop();
        }
        
        value = popStack.top();
        popStack.pop();
        
        while(!popStack.empty()){
            pushStack.push(popStack.top());
            popStack.pop();
        }
        
        return value;
    }
    
    // Space complexity: O(1)
    //  Time complexity: O(2N) = O(N)
    int peek() {
        int value;
        
        while(!pushStack.empty()){
            popStack.push(pushStack.top());
            pushStack.pop();
        }
        
        value = popStack.top();
        
        while(!popStack.empty()){
            pushStack.push(popStack.top());
            popStack.pop();
        }
        
        return value;
    }
    
    // Space complexity: O(1)
    //  Time complexity: O(1)
    bool empty() {
        if(!pushStack.empty()) return false;
        else return true;
    }
};



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
