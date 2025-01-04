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
    int coin[n];
    long long total=0;
    for(int i=0; i<n; ++i) {cin >> coin[i]; total += coin[i];}

    bool dp[total+1] = {};
    dp[0] = true;

    // learn: using coin only once and why go backwards inner loop
    for(auto c:coin){
        for(int i=total-c; i>=0; i--){
            // sum=i achievable without this coin
            // could use this coin to make another sum=(i+c)
            if(dp[i]) dp[i+c] = true; 
        }

        // cout << "\ncoin:" << c << "  ";
        // for(int i=1; i<=total; ++i) {if(dp[i]) cout << i << " ";} cout << "\n";
    }

    long long count = 0;
    for(int i=1; i<=total; ++i) {if(dp[i])count++;}
    cout << count << "\n";
    for(int i=1; i<=total; ++i) {if(dp[i]) cout << i << " ";}
}
