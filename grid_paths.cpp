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
    int n; cin >> n;
    string grid[n];
    for(int i=0; i<n; ++i) cin >> grid[i];

    vector<vector<int>> dp(n, vector<int>(n,0));

    // base-case: valid pathway to reach first co-ordinate
    if(grid[0][0] != '*') dp[0][0] = 1;

    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            // default zero valid path for trap.
            if(grid[y][x] == '*') continue; 
            // from left
            if(x-1>=0) dp[y][x] += dp[y][x-1];
            // from top
            if(y-1>=0) dp[y][x] += dp[y-1][x];
            // save modulo 
            dp[y][x] %= MOD;
        }
    }

    cout << dp[n-1][n-1];
}
