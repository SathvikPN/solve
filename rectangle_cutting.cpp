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
    int a,b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));

    // every cut makes two rectangles smaller than original rectangle
    // dp[y][x]: min-cuts to convert (y*x) rectangle into squares 
    for(int y=1; y<=a; ++y){
        for(int x=1; x<=b; ++x){
            // already square 
            if(y==x) {dp[y][x] = 0; continue;}

            // for each vertical cuts
            for(int xcut=1; xcut<x; ++xcut){
                dp[y][x] = min(dp[y][x], 1 + dp[y][xcut] + dp[y][x-xcut]);
            }

            // for each horizontal cuts
            for(int ycut=1; ycut<y; ++ycut){
                dp[y][x] = min(dp[y][x], 1 + dp[ycut][x] + dp[y-ycut][x]);
            }
        }
    }

    cout << dp[a][b] << "\n";

    // for(int i=1; i<=a; ++i){
    //     for(int j=1; j<=b; ++j) cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

}
