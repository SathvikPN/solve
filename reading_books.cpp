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
    long t[n]; 
    long max_time=0, total_time=0;
    for(auto i=0; i<n; ++i) {
        cin >> t[i];
        total_time += t[i];
        max_time = max(max_time, t[i]);
    }
    cout << max(2*max_time, total_time);
}
