// Space complexity: O(1) - 7.6 MB, less than 79.44% of C++ online submissions
//  Time complexity: O(N^2 log N) - 0 ms, faster than 100.00% of C++ online submissions
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         int left, right;
                
//         while(stones.size() > 1){
//             sort(stones.begin(), stones.end());
//             left = stones.size() - 2, right = stones.size() - 1;
            
//             if(stones[left] == stones[right]){
//                 stones.erase(stones.begin() + right);
//                 stones.erase(stones.begin() + left);
//             }
//             else{
//                 stones[left] = stones[right] - stones[left];
//                 stones.erase(stones.begin() + right);
//             }  
//         }
        
//         return stones.size() == 1 ? stones[0] : 0;
//     }
// };



// Space complexity: O(1) - 7.6 MB, less than 79.44% of C++ online submissions
//  Time complexity: O(N log N) - 3 ms, faster than 55.31% of C++ online submissions
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int first, sec;
        priority_queue<int> pq;
        
        for(unsigned int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
                
        while(pq.size() > 1){
            first = pq.top();
            pq.pop();
            
            sec = pq.top();
            pq.pop();
            
            if(first != sec) pq.push(first - sec);
        }
        
        return pq.size() == 1? pq.top() : 0; 
    }
};
