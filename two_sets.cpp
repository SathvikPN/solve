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
    // x, x+1, x+2, x+3 .....
    // except {1,2,3} split equally as (1,2) (3)
    // any quadlets {x, x+1, x+2, x+3} split equally as (x, x+3) (x+1, x+2)
    if (n%4 !=0 && n%4 !=3) {cout << "NO"; return;}

    cout << "YES\n";
    
    if (n%4 == 3) { cout << (((n-3)/4) * 2) + 2 << "\n1 2 "; i=4;}
    else {cout << (n/4)*2 << "\n"; i=1;}
    for (; i<=n; i+=4) cout << i << " " << i+3 << " ";
    
    cout << "\n";

    if (n%4 == 3) { cout << (((n-3)/4) * 2) + 1 << "\n3 "; i=4;}
    else {cout << (n/4)*2 << "\n"; i=1;}
    for (; i<=n; i+=4) cout << i+1 << " " << i+2 << " ";

}
