// Space complexity: O(2N) = O(N) -  less than 67.65% of C++ online submissions
//  Time complexity: O(1) - faster than 98.61% of C++ online submissions
class MinStack {
public:
    stack<pair<int, int>> minStack;
    
    MinStack() {}
    
    // Time complexity: O(1)
    void push(int val) {
        if(minStack.empty() || val < minStack.top().second) minStack.push(make_pair(val, val));
        else minStack.push(make_pair(val, minStack.top().second));
    }
    
    // Time complexity: O(1)
    void pop() {
        minStack.pop();
    }
    
    // Time complexity: O(1)
    int top() {
        return minStack.top().first;
    }
    
    // Time complexity: O(1)
    int getMin() {
        return minStack.top().second;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
