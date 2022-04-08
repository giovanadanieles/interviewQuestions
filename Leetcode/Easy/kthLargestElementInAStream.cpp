// Space complexity: O(K) - 19.9 MB, less than 63.09% of C++ online submissions
//  Time complexity: O(N log N) - 53 ms, faster than 36.75% of C++ online submissions
// class KthLargest {
// public:
//     int capacity;
//     priority_queue<int, vector<int>, greater<int>> kth;
    
//     KthLargest(int k, vector<int>& nums) {
//         sort(nums.begin(), nums.end(), greater<int>());
        
//         for(int i = 0; i < nums.size() && i < k; i++){
//             kth.push(nums[i]);
//         }
        
//         capacity = k;
//     }
        
        //
//     int add(int val) {
//         if(kth.size() < capacity || val > kth.top()) kth.push(val);
//         if(kth.size() > capacity) kth.pop();
        
//         return kth.top();
//     }
// };



// Space complexity: O(K) - 19.8 MB, less than 91.17% of C++ online submissions
//  Time complexity: O(N log N) - 37 ms, faster than 74.31% of C++ online submissions
class KthLargest {
public:
    int capacity;
    priority_queue<int, vector<int>, greater<int>> kth;
    
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            kth.push(nums[i]);
        }
        
        while(kth.size() > k) kth.pop();
        
        capacity = k;
    }
    
    int add(int val) {
        kth.push(val);
        
        if(kth.size() > capacity) kth.pop();
        
        return kth.top();
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
