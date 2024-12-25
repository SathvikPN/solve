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
    int n, m, x; cin >> n >> m;
    multiset<long> tickets;
    for(auto i=0; i<n; i++){
        cin >> x;
        tickets.insert(x);
    }

    for(auto i=0; i<m; i++){
        cin >> x;
        auto it = tickets.upper_bound(x); // immediate next element greater than x
        if(it == tickets.begin()) {
            cout << -1 << "\n";
            continue;
        }

        cout << *(--it) << "\n";
        tickets.erase(it);
    }
}