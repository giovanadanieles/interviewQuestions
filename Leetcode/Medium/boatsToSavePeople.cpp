// Space complexity: O(1) - 42 MB, less than 10.53% of C++ online submissions
//  Time complexity: O(N log N) - 128 ms, faster than 30.94% of C++ online submissions
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int numOfBoats = 0, left, right;
        
        sort(people.begin(), people.end());
        
        left = 0, right = people.size() - 1;
        while(left <= right){
            if(people[left] + people[right] <= limit) left++, right--;
            else right--;
                
            numOfBoats++;
        }
        
        return numOfBoats;
    }
};
