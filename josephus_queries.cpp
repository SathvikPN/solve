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

int josephusKthChild(int n, int k){
    if(n==1) return 1; // 1-based position, one and only child
    if(2*k <= n) return 2*k;
    if(2*k == n+1) return 1;

    //k=4: 1,2,3,4,5   ==>   3,5 (n=2, k=1)  returns 2      (ans=5)
    //k=4: 1,2,3,4,5,6 ==> 1,3,5 (n=3, k=1)  returns 2      (ans=3)
    int newN = n/2;
    int newK = k - ((n/2) + (n&1)); // if odd, (n/2)+1 k's used
    int newChild = josephusKthChild(newN, newK);
    
    if(n&1)     return (2*newChild) + 1;
    else        return (2*newChild) - 1;
}

void solution(){
    int q; cin >> q;
    while(q--){
        int n,k; cin >> n >> k;
        cout << josephusKthChild(n,k) << endl;
    }
}
