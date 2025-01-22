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
    if(n==2 || n==3) {cout << "NO SOLUTION"; return;}
    for(int i=2; i<=n; i+=2) cout << i << " ";
    for(int i=1; i<=n; i+=2) cout << i << " ";
}
