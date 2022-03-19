// Ref: https://www.youtube.com/watch?v=7ABFKPK2hD4

// Space: 169.6 MB, less than 56.42% of C++ online submissions
//  Time: 424 ms, faster than 86.16% of C++ online submissions
class LRUCache {
public:
    struct Node{
        int key, val;
        Node *prev, *next;
        
        Node(int key_, int val_) : key(key_), val(val_), prev(nullptr), next(nullptr) {}
    };
    
    int maxCapacity;
    unordered_map<int, Node*> cache;
    Node *leastRecent, *mostRecent;
    
    LRUCache(int capacity) {
        maxCapacity = capacity;
        
        leastRecent = new Node(0, 0); //helps to find the least recently used element
        mostRecent = new Node(0, 0);  //helps to find the most recently used element
            
        leastRecent->next = mostRecent;
        mostRecent->prev = leastRecent;
    }
    
    // Time complexity: O(1)
    void removeNode(Node *node){
        Node *prev, *next;
        
        prev = node->prev;
        next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    // Time complexity: O(1)
    void insertNode(Node *node){ // inserting at rightmost 
        Node *prev, *next;
        
        prev = mostRecent->prev;
        next = mostRecent;
        
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }
    
    // Time complexity: O(1)
    int get(int key) {
        if(cache.find(key) != cache.end()){
            //updating the most recent
            removeNode(cache[key]);
            insertNode(cache[key]);
            
            return cache[key]->val; 
        }
        else return -1;
    }
    
    // Time complexity: O(1)
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) removeNode(cache[key]);

        cache[key] = new Node(key, value);
        
        insertNode(cache[key]);
        
        if(cache.size() > maxCapacity){
            Node* lru = leastRecent->next; // remove and delete the least recently used
            
            removeNode(lru);
            cache.erase(lru->key);
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
