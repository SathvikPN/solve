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
    int dice_values[] = {1,2,3,4,5,6};

    long long dp[n+1] = {0};
    for(int i=1; i<=n; ++i) {
        long long iways = 0;
        for (int dice:dice_values) {
            if(i < dice) break;
            if(i == dice) iways = iways + 1;
            else          iways = iways + dp[i-dice];
        }
        dp[i] = iways % MOD;
        // cout << "i=" << i << " ways=" << iways << "\n";
    }

    cout << dp[n];


}
