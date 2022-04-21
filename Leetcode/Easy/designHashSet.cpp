// Space complexity: O(10 ^ 6) - 303.5 MB, less than 6.07% of C++ online submissions
//  Time complexity: O(1) - 575 ms, faster than 9.74% of C++ online submissions
class MyHashSet {
public:
    vector<int> hashset;
    
    MyHashSet() {
        for(unsigned int i = 0; i < 1000001; i++) hashset.push_back(0);
    }
    
    void add(int key) {
        hashset[key] = 1;
    }
    
    void remove(int key) {
        hashset[key] = 0;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
