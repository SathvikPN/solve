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
    long long countBitStrings=1;

    // 2^n handle overflow 
    for(int i=1; i<=n; ++i){
        countBitStrings = countBitStrings * 2;
        countBitStrings = countBitStrings % MOD;
    }
    cout << countBitStrings;
}
