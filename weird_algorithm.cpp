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
    while(1){
        cout << n << " ";
        if(n==1) break;
        if(n&1) n=(n*3)+1;
        else n=n/2;
    }
}