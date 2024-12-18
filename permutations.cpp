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
    long long n, i; cin >> n;

    if (n==2 || n==3) {cout << "NO SOLUTION"; return;}

    if(n&1) i=n; else i=n-1;
    for(;i>0; i=i-2) cout << i << " ";

    if(n&1) i=n-1; else i=n;
    for(;i>0; i=i-2) cout << i << " ";
}
