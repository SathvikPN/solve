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
    int n; cin >> n;
    int p[n]; for(auto i=0; i<n; ++i) cin >> p[i];

    sort(p, p+n);

    int median = p[n/2]; // 1,5,6
    long cost=0;
    for(auto x:p) cost+=abs(x-median);
    cout << cost;
}
