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
        set<pair<int,int>> affectedPairs;

        // Collect the unique values being swapped and their neighbors
        for(int x:{values[a], values[b]}){
            // x=values[a], x=values[b]
            if(x>1) affectedPairs.insert({x-1, x  }); // prev number
            if(x<n) affectedPairs.insert({x  , x+1}); // next number
        }

        // Remove the contribution of affected elements before the swap
        for(auto x: affectedPairs){
            if(pos[x.first] > pos[x.second]) rounds--;
        }


        // perform swap
        pos[values[a]] = b;
        pos[values[b]] = a;
        swap(values[a], values[b]);

        // Re-add contributions of affected elems after swap
        for(auto x: affectedPairs){
            if(pos[x.first] > pos[x.second]) rounds++;
        }

        cout << rounds << "\n";
    }
}

// idx:         1 2 3 4 5
// values:      4 2 1 5 3

// idx:         1 2 3 4 5 
// positions:   3 2 5 1 4

// swap1 ------------------------

// idx:         1 2 3 4 5
// values:      4 1 2 5 3

// idx:         1 2 3 4 5 
// positions:   2 3 5 1 4  


