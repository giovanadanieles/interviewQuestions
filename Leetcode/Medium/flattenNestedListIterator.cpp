/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */



// Ref: https://www.youtube.com/watch?v=PtJ6APpEhOU
// Space complexity: O(numOfIntegers) - 14.9 MB, less than 18.82% of C++ online submissions
//  Time complexity: O(numOfIntegers) - 19 ms, faster than 58.97% of C++ online submissions
class NestedIterator {
public:
    int curIndex = 0;
    vector<int> integerValues;
    vector<NestedInteger> nestedList;
    
    NestedIterator(vector<NestedInteger> &nestedList_) {
        nestedList = nestedList_;
        flatten(nestedList);
    }
    
    void flatten(vector<NestedInteger> &nestedList){
        for(auto element : nestedList){
            if(element.isInteger()) integerValues.push_back(element.getInteger());
            else flatten(element.getList());
        }
    }
    
    int next() {
        return integerValues[curIndex++];
    }
    
    bool hasNext() {
        return curIndex < integerValues.size();
    }
};



/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
