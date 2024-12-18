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
    // code here
    long long n; cin >> n;

    // each of n pos can be filled with 2 elem (0 or 1)
    // 2x2x2......(n times) = 2^n 
    
    // handle overflow
    long long result = 2;
    for (long long i=1; i<n; i++) {
        result = result * 2;
        result = result % MOD;
    }
    cout << result;
}
