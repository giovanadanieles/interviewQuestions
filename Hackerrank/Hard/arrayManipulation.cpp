#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* const argv[]) {
    long int n, m, p, q, sum, ans = 0, aux = 0;

    cin >> n >> m;

    long int *path = new long int[n+1]();

    for(long int i = 0; i < m; i++){
        cin >> p >> q >> sum;
        path[p] += sum;

        if((q + 1) <= n) path[q + 1] -= sum;
    }

    for(long int i = 1; i <= n; i++){
       aux += path[i];

       ans = max(aux, ans);
    }

    cout << ans << endl;

    return 0;
}
