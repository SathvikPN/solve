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
    
    if(n%4==0 || n%4==3)  {cout << "YES\n";}
    else                  {cout << "NO\n"; return;}

    // 1,2,3 only triplet 1+2==3, 
    // in-general quadlet {x, x+1, x+2, x+3}
    // sum(x, x+3)==sum(x+1, x+2)

    int start, setCount = (n/4)*2;

    start=1;
    if(n%4 == 3) {
        cout << 2 + setCount << "\n";
        cout << 1 << " " << 2 << " ";
        start=4;
    } else cout << setCount << "\n";
    
    for(int i=start; i<=n; i+=4) {cout << i << " " << i+3 << " ";}

    cout << "\n";

    start=1;
    if(n%4 == 3) {
        cout << 1 + setCount << "\n";
        cout << 3 << " ";
        start=4;
    } else cout << setCount << "\n";

    for(int i=start; i<=n; i+=4) {cout << i+1 << " " << i+2 << " ";}
}
