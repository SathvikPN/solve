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
    int x[n];
    for(auto i=0; i<n; ++i) cin >> x[i];
    
    sort(x, x+n);
    long long smallest_sum=1;
    for(auto i=0; i<n; ++i){
        if(x[i] > smallest_sum) break;
        smallest_sum = smallest_sum + x[i];
    }
    cout << smallest_sum;
}
