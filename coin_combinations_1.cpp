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
    long long n,x; cin >> n >> x;
    long long denominations[n]; for(size_t i=0; i<n; ++i) cin >> denominations[i];

    // unlimited supply of coins
    vector<long long> dp(x+1,0);

    // base-case: dp[s-c] current-coin can achieve 's'
    dp[0] = 1; 

    for(long long s=1; s<=x; ++s) {
        long long ways = 0;
        for(auto c:denominations) {
            if(s-c>=0) {
                ways = ways + dp[s-c];
            }
        }
        dp[s] = ways % MOD;
    }
    cout << dp[x];
}
