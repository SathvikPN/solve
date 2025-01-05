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

// learn: https://www.youtube.com/watch?v=g6OxU-hRGtY (explanation)

// position of MSB bit (0-based-idx from right-to-left) (-1 if n=0)
long long getMSB(long long n){
    long long pos = -1; 
    while(n){pos++; n=n>>1;}
    return pos;
}

/*
bits(N) = floor(log2(N))+1
bits(10^15) = log2(10^15) = 15*log2(10) = 49.82 ===> 50 bits
N = 11

 0 0000
 1 0001
 2 0010
 3 0011
 4 0100
 5 0101
 6 0110
 7 0111
--------------
 8 1000
 9 1001
10 1010
11 1011

*/
long long countSetbitsTillN(long long n){
    if(n==0) return 0;
    long long x = getMSB(n); // leftmost-set-bit: 0-based-right-to-left-idx (n=11 => x=3)

    // (2^x == 1<<x)
    // count set bits till last complete pattern ---
    // num/2 1s from each bit-column (x=3)
    long long setbitsTillEndpn = ((1LL<<x)/2)*x; // (8/2)*3
    // learn: 1LL<<x if x>32 then 1<<x treat as integer overflow, 
    // so 1LL: treat 1 as long long type to get AC solution

    long long msbSetbitsAfterCompletePattern = n - ((1LL<<x)-1); // 11-(8-1)

    /* reduced to subproblem
    8  1|000
    9  1|001
    10  1|010
    11  1|011
    */
    long long nextN = n-(1LL<<x);
    return setbitsTillEndpn + msbSetbitsAfterCompletePattern + countSetbitsTillN(nextN);
}

// n <= 10^15  O(1) solution required
// n <= 10^9  O(n) works
void solution(){
    long long n; cin >> n;
    cout << countSetbitsTillN(n);
}



