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
    vector<int> dp(n+1);
    dp[0] = 0; // zero steps to reach from 0 to zero.

    for(int i=1; i<=n; ++i) {
        int x = i; // temporary copy since we alter this for digit extraction
        int leastSteps = INT_MAX;
        while(x){
            int lastDigit = x%10;
            if(lastDigit) leastSteps = min(leastSteps, 1 + dp[i-lastDigit]);
            x = x/10;
        }
        dp[i] = leastSteps;
    }
    cout << dp[n];
}
