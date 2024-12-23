#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7;
 
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

void solution(){
    long long n, q, a, b; cin >> n >> q;
    long long x, y, logn=log2(n);
    long long prevRangeSize, currRangeSize;
    long long sparseTable[logn][n];

// RMQ(2,9)
// 2^y\x: 0 1 2 3 4 5 6 7 8 9
//   -------------------------- 
//   2^0: 4 2 3 7 1 5 3 3 9 6 
//   2^1:     3   1   3   6
//   2^2:     1       3
//   2^3:     1

// RMQ(2,6) rangeSize=5
// 2^y\x: 0 1 2 3 4 5 6 7 8 9
//   -------------------------- 
//   2^0: 4 2 3 7 1 5 3 3 9 6 
//   2^1:     3   1   3   
//   2^2:     1       3

    // base case (y=0)
    for(x=0; x<n; x++) cin >> sparseTable[0][x];
    // recursive case
    for(y=1; y<=logn; y++){
        currRangeSize = 1 << y;
        for(x=0; (x+currRangeSize-1) < n; x++){
            prevRangeSize = 1 << (y-1);
            sparseTable[y][x] = min(sparseTable[y-1][x], sparseTable[y-1][x + prevRangeSize]);
        }
    }
    while(q--){
        cin >> a >> b; a--; b--; // 0-based-idx
        long long k = log2(b-a+1); // largest power of 2 for range size
        cout << min(sparseTable[k][a], sparseTable[k][b-(1<<k)+1]);
        cout << "\n";
    }
}
