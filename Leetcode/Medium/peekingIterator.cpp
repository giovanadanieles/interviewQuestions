/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */



// Space: 7.5 MB, less than 72.00% of C++ online submissions
//  Time: 4 ms, faster than 59.03% of C++ online submissions
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        
        hasPeeked = false;
	    it = new Iterator(nums);  
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(hasPeeked == false){
            hasPeeked = true;
            peekedValue = it->next();
        }
        
        return peekedValue;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(hasPeeked == true){
            hasPeeked = false;
            return peekedValue;
        }
        else return it->next();
    }
	
	
	bool hasNext() const {
	    return hasPeeked || it->hasNext();
	}
    
private:
    bool hasPeeked;
    int peekedValue;
    Iterator *it;
};
