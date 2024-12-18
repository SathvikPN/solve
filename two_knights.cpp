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
    long long n, k; cin >> n;

    // no space for two knights in 1x1 board
    cout << 0 << "\n"; 

    long long totalPos, totalCombo, attackRectangles, attackCombo;
    for (long long k=2; k<=n; k++) {
        // C(n,k) = n! / k!(n-k!)    n-choose-k, here k-pos choose 2 knight pos
        totalPos = k*k;
        totalCombo = ((totalPos) * (totalPos-1)) / 2;

        // (width, height): (2,3) + (3,2) rectangles inside (k,k) rectangle
        attackRectangles = ((k-2+1) * (k-3+1)) + ((k-3+1) * (k-2+1));
        attackCombo = attackRectangles * 2;
        cout << totalCombo - attackCombo << "\n";
    }
}
