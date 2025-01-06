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


// learn: fenwick-tree(binary-i-tree) - https://www.youtube.com/watch?v=uSFzHCZ4E-8

long long n, q;
// point update for binary-idx-tree -----------------------------
void update(long long tree[], long long i, long long delta){
    while(i<=n){
        tree[i] = tree[i] + delta;
             i  = i + (i & -i);
    }
}

// prefix-sum [0,i] ---------------------------------------------
long long prefix(long long tree[], long long i){
    long long sum = 0;
    while(i>0){
        sum = sum + tree[i];
          i = i - (i & -i);
    }
    return sum;
}

void solution(){
    cin >> n >> q;
    long long arr[n+1];
    long long tree[n+1] = {}; // init 0-values

    for(long long i=1; i<=n; ++i){
        cin >> arr[i];
        update(tree, i, arr[i]);
    }

    while(q--){
        long long type; cin >> type;
        if(type == 1){
            long long idx, newValue; cin >> idx >> newValue;
            long long delta = newValue - arr[idx];
            arr[idx] = newValue;
            update(tree, idx, delta);
        } else {
            long long left, right; cin >> left >> right;
            cout << prefix(tree, right) - prefix(tree, left-1) << "\n";
        }
    }
}
