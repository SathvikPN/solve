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
    long long n,i,count=0; cin >> n;
    for(i=5; i<=n; i=i*5) {
        count += n/i;
    }
    cout << count;
}
