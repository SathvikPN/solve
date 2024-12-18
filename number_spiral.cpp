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
    // code here
    long long t, y, x, n, N; cin >> t;
    while(t--) {
        cin >> y >> x;
        n = max(y,x);
        N = n*n;
        if (n&1) cout << N - (y-1) - (n-x) << "\n";
        else cout << N - (x-1) - (n-y) << "\n";
    }
}