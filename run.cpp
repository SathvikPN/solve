#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7; // 10^9 + 7
 
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

void solution(){
    int n,q; cin >> n >> q;
    // read array directly into sparseTable first row (len=1)
    long long sparseTable[(int)log2(n)+1][n];
    for(int i=0; i<n; ++i) cin >> sparseTable[0][i];

    // build sparseTable 
    for(int y=1; y<=log2(n); ++y){
        int prevRangeSize = 1<<(y-1); // 2^(y-1)
        for(int x=0; (x+prevRangeSize)<n; ++x){
            sparseTable[y][x] = min(sparseTable[y-1][x], sparseTable[y-1][x+prevRangeSize]);
        }
    }

    while(q--){
        int a,b; cin >> a >> b; a--; b--;
        cout << min(sparseTable[(int)log2(b-a+1)][a], sparseTable[(int)log2(b-a+1)][b-(1<<(int)(log2(b-a+1)))+1]) << "\n";
    }
}
