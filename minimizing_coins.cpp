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
    int n,x;
    cin >> n >> x;

    int coinValue[n];
    for(int i=0; i<n; ++i) cin >> coinValue[i];

    // learn: int arr[5] = {2}; ==> {2,0,0,0,0}
    vector<long long> dp(x+1, LLONG_MAX); // dp[i] = minimal coins to form i
    dp[0] = 0;
    for(int s=1; s<=x; ++s) {
        for(auto c:coinValue) {
            // sub-sum achievable
            if((s-c >= 0) && (dp[s-c] != LLONG_MAX)){
                dp[s] = min(dp[s], 1 + dp[s-c]);
            }
        }
        // cout << s << " " <<  dp[s] << "\n";
    }

    if(dp[x] == LLONG_MAX) cout << -1;
    else                   cout << dp[x];

}
