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
    int n,x; cin >> n >> x;
    vector<int> denominations(n);
    for(int i=0; i<n; ++i) cin >> denominations[i];


    vector<long long> dp(x+1, 0);
    dp[0] = 1;

    // for(int i=0; i<=x; ++i) cout << i << " "; cout << "<-sum\n";
    for(auto c:denominations){
        for(int i=c; i<=x; ++i){
            dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
        // for(auto j:dp) cout << j << " "; cout << "[" << c << "] coin\n";
    }

    cout << dp[x];
}
