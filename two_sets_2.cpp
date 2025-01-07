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
    long long n; cin >> n;
    long long total = n*(n+1)/2;
    if(total&1) {cout << 0; return;} // odd sum, cannot equally divide for 2 set
 
    long long target = total/2; // sum-of-each-set
    long long dp[target+1] = {}; // dp[i]: no. ways to reach target i
    dp[0] = 1;

    // each num used only once 
    // i<n because as per our logic 
    // we are calculating for set not having n, it will be in the opposite set
    for(long long i=1; i<n; i++){
        for(long long j=target-i; j>=0; j--){
            dp[j+i] += dp[j];
            dp[j+i] %= MOD;
        }
    }
 
    cout << dp[target];
}