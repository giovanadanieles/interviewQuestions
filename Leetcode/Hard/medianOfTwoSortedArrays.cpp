// Space complexity:
//  Time complexity: 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize, halfSize, left, right, middleA, middleB;
        double leftA, rightA, leftB, rightB, ans = 0;
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        
        if (A.size() > B.size()) swap(A, B);
        
        totalSize = nums1.size() + nums2.size();
        halfSize = totalSize / 2;
                
        // binary search on A because A is the smallest array
        left = 0, right = (int)A.size() - 1;
        while(true){
            middleA = left <= right ? (right + left) / 2 : -1; // A
            middleB = halfSize - middleA - 2;    // B
            
            leftA = (middleA >= 0) ? A[middleA] : -1e7;
            rightA = (middleA + 1 < A.size()) ? A[middleA + 1] : 1e7;
            
            leftB = (middleB >= 0) ? B[middleB] : -1e7;
            rightB = (middleB + 1 < B.size()) ? B[middleB + 1] : 1e7;
            
            // we found the correct partition
            if(leftA <= rightB && leftB <= rightA) {
                // odd case
                if(totalSize % 2 == 1){
                    if(rightA <= rightB) ans = rightA;
                    else ans = rightB;
                }
                // even case
                else{
                    if(leftA >= leftB) ans = leftA;
                    else ans = leftB;
                    
                    if(rightA <= rightB) ans += rightA;
                    else ans += rightB;
                    
                    ans /= 2;
                }
                
                break;
            }
            else if(leftA > rightB){ // too many elements in A
                right = middleA - 1;
            }
            else{ // we need to increase size of A partition
                left = middleA + 1;
            } 
        }
        
        return ans;
    }
};
