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

// learn: understand intuitions - https://codeforces.com/blog/entry/70018

/*
sum of 2 players = sum of input list
(score1 - score2): player1 tries to max, player2 tries to minimize
dp[left][right]: difference of score(score1-score2) if game in interal {left ... right}

left==right: single element, player1 has to take it

choose either leftmost or rightmost
chose left: 
    player2 plays {left+1 ... right}
    if player1 played {left+1 ... right}     score1-score2: dp[left+1][right]
    since subproblems is finding this difference for current player,
    output of smaller subproblems donot change irrespective of who is playing currently
    - if A plays {left...right}       dp[left][right] = scoreA - scoreB
    - then B plays {left+1 ..right}   dp[left+1][right] = scoreB - scoreA
    - OR B plays {left....right-1}    dp[left][right-1] = scoreB - scoreA
thus,
    if player1 chose left,
    diff of scoreA-scoreB: x[left] - dp[left+1][right]      (x[left] - (scoreB-scoreA)) == x[left] + scoreA - scoreB
    if player1 chose right,
    diff of scoreA-scoreB: x[right] - dp[left][right-1]

    player1 chooses max(leftChoice, rightChoice)

    dp[0][n-1]: scoreA-scoreB across entire list
    
    xsum = scoreA + scoreB

hence, 
    (xsum + dp[0][n-1])/2 == (scoreA+scoreB+scoreA-scoreB)/2 == scoreA

*/

void solution(){
    int n; cin >> n;
    long long xsum = 0;
    int x[n]; 
    for(int i=0; i<n; ++i) {
        cin >> x[i];
        xsum = xsum + x[i];
    }

    // 2D vector
    vector<vector<long long>> dp(n, vector<long long>(n));

    for(int left=n-1; left>=0; left--){
        for(int right=left; right<n; right++){
            if(left==right){
                dp[left][right] = x[left];
            } else {
                dp[left][right] = max(
                    x[left]  - dp[left+1][right],
                    x[right] - dp[left][right-1]
                );
            }
        }
    }
    cout << (xsum + dp[0][n-1]) / 2 << endl;
}
