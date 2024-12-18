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
    long long n, x; cin >> n;
    long long target = (n*(n+1))/2;
    long long current = 0;
    while(--n) {cin >> x; current+=x;}
    cout << target - current;
}
