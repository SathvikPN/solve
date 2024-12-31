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
    int n,m; cin >> n >> m;
    int values[n+1], pos[n+1]; // values & positions arrays
    for(int i=1; i<=n; ++i) {
        cin >> values[i];
        pos[values[i]] = i;
    }

    // initial number of rounds (breakpoints)
    int rounds=1;
    for(int i=2; i<=n; ++i){
        if(pos[i] < pos[i-1]) rounds++;
    }

    int a,b;
    while(m--){
        cin >> a >> b; // Indices of elements to swap
        unordered_set<int> affected;

        // Collect the unique values being swapped and their neighbors
        for(int x:{values[a], values[b]}){
            // x=values[a], x=values[b]
            affected.insert(x);
            if(x>1) affected.insert(x-1); // prev number
            if(x<n) affected.insert(x+1); // next number
        }

        // Remove the contribution of affected elements before the swap
        for(int x: affected){
            if(pos[x]   < pos[x-1]) rounds--;
            if(pos[x+1] < pos[x])   rounds--;
        }


        // perform swap
        pos[values[a]] = b;
        pos[values[b]] = a;
        swap(values[a], values[b]);

        // Re-add contributions of affected elems after swap
        for(int x: affected){
            if(pos[x]   < pos[x-1]) rounds++;
            if(pos[x+1] < pos[x])   rounds++;
        }

        cout << rounds;
    }
}
