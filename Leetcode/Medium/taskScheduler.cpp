// Space complexity: O(N) - less than 29.49% of C++ online submissions
//  Time complexity: O(M * N), M = tasks size, N = idle; faster than 65.32% of C++ online submissions
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0, count;
        queue<pair<int, int>> q; //count, timeAvailable
        priority_queue<int> maxHeap;
        unordered_map<char, int> charOccurrences;
        
        for(unsigned int i = 0; i < tasks.size(); i++){
            charOccurrences[tasks[i]]++;
        }
        
        unordered_map<char, int>::iterator it;
        for(it = charOccurrences.begin(); it != charOccurrences.end(); it++){
            maxHeap.push(it->second);
        }
        
        while(!maxHeap.empty() || !q.empty()){
            time++;
            
            if(!maxHeap.empty()){
                count = maxHeap.top() - 1;
                maxHeap.pop();
                
                if(count != 0){
                    q.push(make_pair(count, time + n));
                }
            }
            
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        
        return time; 
    }
};
