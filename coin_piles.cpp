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
    long long t,a,b; cin >> t;
    while(t--){
        cin >> a >> b;
        if(a<b) swap(a,b);
        if ((2*b) < a) {cout << "NO\n"; continue;;} // 1s < 2s
        if ((a+b)%3) cout << "NO\n"; // every transaction reduce by 3, a reminder mean unclear at end
        else cout << "YES\n";
    }
}
