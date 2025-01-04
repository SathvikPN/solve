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
    int t; cin >> t;
    int testCase[t];
    int maxHeight=0;
    for(int i=0; i<t; ++i){
        cin >> testCase[i];
        if(testCase[i] > maxHeight) maxHeight = testCase[i];
    }
    
    // dp[height][type]: 
    // no. ways to make tower till height with current block-type 
    // [0]=[ ] [1]=[][] 
    vector<vector<long long>> dp(maxHeight+1, vector<long long> (2, 0));

    // base case: h==1
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int h=2; h<=maxHeight; ++h){
        // 2 (horizontal on top, extend horizontal down) 
        // 1 (half-horizontal on top)
        // base: [  ]
        dp[h][0] = (2 * dp[h-1][0] % MOD) + (1 * dp[h-1][1] % MOD);
        dp[h][0] %= MOD;

        // 1 (horizontal on top, cannot extend down) 
        // 4 (hh top, extendLeftColDown, extendRightColDown, extendBothColDown)
        // base: [][]
        dp[h][1] = (1 * dp[h-1][0] % MOD) + (4 * dp[h-1][1] % MOD);
        dp[h][1] %= MOD;
    }


    // print outputs
    for(auto h:testCase) cout << (dp[h][0] + dp[h][1]) % MOD << "\n";
}
