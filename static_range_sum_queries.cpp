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
    long long n, q, a, b; cin >> n >> q;
    long long arr[n];
    for (auto i=0; i<n; i++) cin >> arr[i];
    long long psum[n]; psum[0] = arr[0];
    for (auto i=1; i<n; i++) psum[i] = psum[i-1] + arr[i];
    while(q--){
        cin >> a >> b; a--; b--; // 0-based-idx
        if (a==0) cout << psum[b];
        else      cout << psum[b]-psum[a-1];
        cout << "\n";
    }
}
