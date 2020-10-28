// The idea of this problem is to find all the cycles involved 
//in the sorting - the minimum number of swaps will be the sum 
//of (sz_cycles - 1).


/* 
For example:

[ 0  1  2  3   4  5  6  7  8  9 ]         -> index of array

[ 6  3  8  10  7  4  5  2  1  9 ]         -> given array
 
[ 5  2  7  9   6  3  4  1  0  8 ]         -> position where the numbers should be 

In this sense, we have the following cycles:
 6 -> 4 -> 10 -> 9 -> 1 -> 6  (size 5)

 3 -> 8 -> 2 -> 3             (size 3)

 7 -> 5 -> 7                  (size 2)

It is possible to say that the members of each cycle are shuffled among themselves, so it does not make sense to perform swaps with elements outside the cycle.

Therefore, the solution will be the sum of (cycle sizes minus 1).

*/
int minimumSwaps(vector<int> arr, int n) {
    int ans = 0, visited[n]; 
    int pos, pos_should, cycle_sz;

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            pos = i;
            pos_should = arr[i] - 1;
            cycle_sz = 1;

            visited[i] = 1;

            // While I can't find the first position I worked on (which indicates the                //end of the cycle)
            while(pos_should != i){
                visited[pos_should] = 1;
                pos = pos_should;
                pos_should = arr[pos_should] - 1;

                cycle_sz++;
            }

            ans += (cycle_sz - 1);
        }
    }

    return ans;
}
