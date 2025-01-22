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
    long long t, y, x, d, m; cin >> t;
    while(t--){
        cin >> y >> x;
        d = max(y,x);
        m = d*d;
        if(m&1) cout << m - (y-1) - (d-x);
        else    cout << m - (x-1) - (d-y);
        cout << "\n";
    }
}
