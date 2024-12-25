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
    long long n, count=1; cin >> n;
    long long arr[n];
    for(auto i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(auto i=1; i<n;i++) if(arr[i-1]!=arr[i]) count++;
    cout << count;
}
