// TIME LIMIT EXCEEDED :(
// class MedianFinder {
// public:
//     int totalSize;
//     map<int, int> frequencies;
    
//     MedianFinder() {
//         totalSize = 0;
//     }
    
//     // Time: O(logN) [if called M times, M log N]
//     void addNum(int num) {
//         totalSize++;
//         frequencies[num]++;
//     }
    
//     // Time: O(N)
//     double findMedian() {
//         double median = 0;
//         double gotLeft = false, gotRight = false;
//         int numElem = 0, middleLeft, middleRight = -1;
        
//         if(totalSize % 2 == 1) middleLeft = (totalSize + 1) / 2; //middleLeft = 2
//         else{
//             middleLeft = totalSize / 2;
//             middleRight = middleLeft + 1;
//         }
                
//         for(auto it = frequencies.begin(); it != frequencies.end(); it++){
//             numElem += it->second;
            
//             if(numElem >= middleLeft && gotLeft == false){
//                 median += it->first;
//                 gotLeft = true;
                
//                 if(middleRight == -1) break;
//             }
//             if(middleRight != -1 && numElem >= middleRight && gotRight == false){
//                 median += it->first;
//                 gotRight = true;
//             }
            
//             if(gotLeft == true && gotRight == true) break;
//         }
                
//         return middleRight != -1 ? median / 2 : median;
//     }
// };



// Ref: https://www.youtube.com/watch?v=itmhHWaHupI

// Space: 116.9 MB, less than 90.22% of C++ online submissions
//  Time: 477 ms, faster than 44.53% of C++ online submissions
class MedianFinder {
public:
    // smallHeap (maxHeap) <= largeHeap (minHeap), smallHeap_sz ~~ largeHeap_sz
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    priority_queue<int> smallHeap;
    
    MedianFinder() {}
    
    // Time: log N (if executed M times, M log N)
    void addNum(int num) {
        smallHeap.push(num);
        
        // make sure every element in smallHeap is <= every element in largeHeap
        if(!smallHeap.empty() && !largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        
        // is the difference between sizes larger than 1?
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    // Time: O(1)
    double findMedian() {
        // first case: odd length
        if(smallHeap.size() > largeHeap.size()) return smallHeap.top();
        else if(largeHeap.size() > smallHeap.size()) return largeHeap.top();
        
        // sec case: even length
        return (double)((smallHeap.top() + largeHeap.top()) / 2.0);
    }
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
