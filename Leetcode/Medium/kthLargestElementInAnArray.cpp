// Space complexity: O(N) - 10.3 MB, less than 21.09% of C++ online submissions
//  Time complexity: O(NlogN) - 9 ms, faster than 69.27% of C++ online submissions
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k){
//         int cur = -1;
//         priority_queue<int> pq;
        
//         for(auto num : nums) pq.push(num);
        
//         while(k > 0) cur = pq.top(), pq.pop(), k--;
        
//         return cur;
//     }
// };



// Space complexity: O(K) - 10.2 MB, less than 36.63% of C++ online submissions
//  Time complexity: O(NlogK) - 8 ms, faster than 80.51% of C++ online submissions
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto num : nums){
            if(pq.size() < k) pq.push(num);
            else if(pq.top() < num) pq.pop(), pq.push(num);   
        }
                
        return pq.top();
    }
};
