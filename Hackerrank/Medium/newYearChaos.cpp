// Complexity: O(n log n)
void minimumBribes(vector<int> q) {
    int dist, ans = 0;

    for(unsigned int i = 0; i < q.size(); i++){
        // the original position of each person (with 0-indexing)
        //is q[i] - 1

        // how far the "q[i] - 1 person" has moved???
        dist = (q[i] - 1) - i;

        // ilegall bribe
        if(dist > 2){
            cout << "Too chaotic" << endl;
            
            return;
        }

        // I stop analyzing how many times the person has bribed and 
        //start analyzing how many times the person has been bribed:

        // If the person was legally bribed...
        if(dist <= 0){
            // Whoever bribed will be, at most, in the position original_pos - 1
            // (max() is needed for 0 position)
            for(int j = max(0, q[i] - 2); j < i; j++){
                if(q[j] - 1 > q[i] - 1) ans++;
            }
        }
    }

    cout << ans << endl;
    
}
