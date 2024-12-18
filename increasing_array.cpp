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
    long long n, i, x, moves=0; cin >> n;
    long long arr[n];
    for (i=0; i<n; i++) {cin >> x; arr[i] = x;}
    
    for(i=1; i<n; i++) {
        if(arr[i-1] <= arr[i]) continue;
        moves += arr[i-1] - arr[i];
        arr[i] = arr[i-1];
    }
    cout << moves;
}
