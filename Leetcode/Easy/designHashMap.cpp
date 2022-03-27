// Space complexity: O(N) - 304.2 MB, less than 8.97% of C++ online submissions
//  Time complexity: O(1) - 573 ms, faster than 7.41% of C++ online submissions
class MyHashMap {
public:
    vector<int> hashMap;
    
    MyHashMap() {
        for(int i = 0; i < 1000000; i++) hashMap.push_back(-1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};



/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
