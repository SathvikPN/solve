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

long long recursiveModularBinaryExponentiation(int a, int b, const long long m){
    if(b==0) return 1;

    long long result = recursiveModularBinaryExponentiation(a, b/2, m);
    if(b&1) return (((result*result)%m) * (a%m))%m;
    else    return (result*result)%m;
}

void solution(){
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        cout << recursiveModularBinaryExponentiation(a,b,MOD) << "\n";
    }
    
}
