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

/* learn: tabulation explanation ----------------------------------------

    replace | insert >>>>
    -------   ------
    delete  | (i,j)
    :
    :


a\b    ''  M  O  V  I  E 
    '' 0   1  2  3  4  5  <<<<< (insertions to convert '' to b)
    L  1   
    O  2
    V  3
    E  4
       ^
       ^
       (deletions to convert a to '')

    dp[y][x]: cost-to-convert a[y] to b[x]
    dp[1][1]: cost-to-convert   0L to   0M 

    compare from end-of-strings
    delete       insert            replace
a:  0L >> 0      0L >> 0LM == 0L   0L >> 0M == 0
b:  0M -- 0M     0M -- 0M  == 0    0M -- 0M == 0

*/

void solution(){
    string a,b;
    cin >> a >> b;
    int na = a.size();
    int nb = b.size();

    vector<vector<int>> dp(na+1, vector<int> (nb+1, INT_MAX));

    // base-cases
    for(int x=0; x<=nb; ++x) dp[0][x] = x;
    for(int y=0; y<=na; ++y) dp[y][0] = y;

    for(int y=1; y<=na; ++y){
        for(int x=1; x<=nb; ++x){
            if(a[y-1] == b[x-1]) { // zero-based idx of string a,b
                // characters match, no extra operations needed, retain previous state
                dp[y][x] = dp[y-1][x-1];
            } else {
                // characters differ, brute force min-cost among all ops
                int deleteCost  = 1 + dp[y-1][x];   
                int insertCost  = 1 + dp[y][x-1];   
                int replaceCost = 1 + dp[y-1][x-1]; 

                dp[y][x] = min({deleteCost, insertCost, replaceCost});
            }
        }
    }

    cout << dp[na][nb];
}
