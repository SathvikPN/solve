#include<bits/stdc++.h>
// #define DEBUG
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
    int n, m; cin >> n >> m;
    int arr[n+1]; for(int i=1; i<=n; ++i) cin >> arr[i]; // 1-based-idx

    // dp[i][x]: ways to fill idx i with value x  (1<=i<=n)(1<=x<=m) 
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // base-case: first elem of arr
    if(arr[1] == 0) { // anything in (1...m)
        for(int i=1; i<=m; ++i) dp[1][i] = 1;
    } else { // only existing value contribute a way
        dp[1][arr[1]] = 1;
    }

    for(int i=2; i<=n; ++i){
        int v;
        if(arr[i] == 0){
            for(v=1; v<=m; ++v){
                if(v-1>=1) dp[i][v] = dp[i][v] + dp[i-1][v-1]; dp[i][v]%=MOD;
                           dp[i][v] = dp[i][v] + dp[i-1][v];   dp[i][v]%=MOD;
                if(v+1<=m) dp[i][v] = dp[i][v] + dp[i-1][v+1]; dp[i][v]%=MOD;
            }
        } else {
            v = arr[i];
            if(v-1>=1) dp[i][v] = dp[i][v] + dp[i-1][v-1]; dp[i][v]%=MOD;
                       dp[i][v] = dp[i][v] + dp[i-1][v];   dp[i][v]%=MOD;
            if(v+1<=m) dp[i][v] = dp[i][v] + dp[i-1][v+1]; dp[i][v]%=MOD;
        }
    }

    long long count = 0;
    for(int v=1; v<=m; ++v){
        count = count + dp[n][v];
    }
    cout << count % MOD;

    #ifdef DEBUG 
    cout << "\n------------------------------------------------------\n";
    cout << "n\\m \n";
    for(int v=1; v<=m; ++v) dp[0][v] = v;
    for(int i=1; i<=n; ++i) dp[i][0] = i;
    for(auto r:dp){
        for(auto c:r) cout << c << " ";
        cout << "\n";
    }
    cout << "\n------------------------------------------------------\n";
    #endif 

}
