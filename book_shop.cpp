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
    int price[n]; for(int i=0; i<n; ++i) cin >> price[i];
    int pages[n]; for(int i=0; i<n; ++i) cin >> pages[i];
    
    vector<int> dp(x+1, 0); // dp[price]=maxPages
    dp[0] = 0; // base-case

    // buy book at most once
    for(auto i=0; i<n; ++i){ // i over books
        for(auto j=x; j>=price[i]; --j){ // j over amount(backwards)
            dp[j] = max(dp[j], pages[i] + dp[j-price[i]]);
        }
    }

    // Correct Order:
    // 1. **Outer loop over books**:
    //    - The loop ensures that each book is considered exactly once in the computation.
    //    - When processing book `i`, 
    //      you only update `dp[j]` considering book `i` for the first time.
    
    // 2. **Inner loop over budget (backward)**:
    //    - This ensures that each budget `j` is updated **after considering whether to include the current book**.
    //    - Iterating backward ensures that we don’t use the same book multiple times in the same iteration.

    cout << dp[x];
}
