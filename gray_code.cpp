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
    int n; cin >> n;
    for(long long i=0; i < (1<<n); i++){ // 1<<n = 2^n
        long long gray_code = i^(i>>1); // gray_code = i XOR (i>>1)
        for(int j=n-1; j>=0; j--){
            cout << ((gray_code>>j)&1); // print j-th bit of gray_code
        }
        cout << endl;
    }
}
