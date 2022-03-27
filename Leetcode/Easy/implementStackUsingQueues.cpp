// Space: 6.8 MB, less than 57.46% of C++ online submissions
//  Time: 7 ms, faster than 9.59% of C++ online submissions
// class MyStack {
// public:
//     queue<int> inOrder, reversed;
    
//     MyStack() {}
    
//     // Time: O(1)
//     void push(int x) {
//         inOrder.push(x);
//     }
    
//     // Time: O(2N) = O(N)
//     int pop() {
//         int element;
        
//         while(inOrder.size() > 1){
//             reversed.push(inOrder.front());
//             inOrder.pop();
//         }
        
//         element = inOrder.front();
//         inOrder.pop();
        
//         while(!reversed.empty()){
//             inOrder.push(reversed.front());
//             reversed.pop();
//         }
        
//         return element;
//     }
    
//     // Time: O(1)
//     int top() {
//         return inOrder.back();
//     }
    
//     // Time: O(1)
//     bool empty() {
//         return inOrder.empty();
//     }
// };



// Space: 6.7 MB, less than 87.64% of C++ online submissions
//  Time: 0 ms, faster than 100.00% of C++ online submissions
class MyStack {
public:
    queue<int> stck;
    
    MyStack() {}
    
    // Time: O(1)
    void push(int x) {
        stck.push(x);
    }
    
    // Time: O(N)
    int pop() {
        int element, numOfEl;
        
        numOfEl = stck.size() - 1;
        
        while(numOfEl > 0){
            stck.push(stck.front());
            stck.pop();
            
            numOfEl--;
        }
        
        element = stck.front();
        stck.pop();
        
        return element;
    }
    
    // Time: O(1)
    int top() {
        return stck.back();
    }
    
    // Time: O(1)
    bool empty() {
        return stck.empty();
    }
};



/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
