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
    long long n, x, csum, tsum; cin >> n; 
    tsum = n*(1+n)/2; // see: operator-precedence, arithmetic-progression-sum
    csum = 0;
    while(n-->1) {
        cin >> x;
        csum += x;
    }
    cout << tsum - csum;
}
