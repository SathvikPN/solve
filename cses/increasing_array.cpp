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
    long long n, prev, curr, moves=0; 
    cin >> n;
    cin >> prev;
    while(n-->1){
        cin >> curr;
        if(prev<=curr)  prev = curr;
        else    moves += prev-curr;
    }
    cout << moves;
}
