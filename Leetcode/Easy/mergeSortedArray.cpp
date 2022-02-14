// Space complexity: O(N) - less than 29.81% of C++ online submissions
//  Time complexity: O(N * log2 N) - faster than 53.89% of C++ online submissions
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int index = 0;
//         map<int, int> numFreq;
        
//         for(int i = 0; i < max(m, n); i++){
//             if(i < m) numFreq[nums1[i]]++;
//             if(i < n) numFreq[nums2[i]]++;
//         }
        
//         map<int, int>::iterator it;
//         for(it = numFreq.begin(); it != numFreq.end(); it++){
//             while(it->second > 0){
//                 nums1[index] = it->first;
//                 it->second--;
                
//                 index++;
//             }
//         }
//     }
// };



// Space complexity: O(1) - less than 29.81% of C++ online submissions
//  Time complexity: O(N + M) - faster than 100.00% of C++ online submissions
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        
        // merging in reverse order
        while(m > 0 && n > 0){
            if(nums1[m - 1] > nums2[n - 1]){
                nums1[last] = nums1[m - 1];
                m--;
            }
            else{
                nums1[last] = nums2[n - 1];
                n--;
            }
            
            last--;
        }
        
        // fill nums1 with leftover nums2 elements
        while(n > 0){
            nums1[last] = nums2[n - 1];
            
            last--, n--;
        }
    }
};
