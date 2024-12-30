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
    int n; cin >> n;

    // 2 3 1 4
    vector<pair<int,int>> x(n+1); // <val,idx>
    for(auto i=1; i<=n; ++i) {cin >> x[i].first; x[i].second = i;}

    sort(x.begin(), x.end());

    int jumps = 0;
    for(auto i=2; i<=n; ++i){
        if(x[i].second < x[i-1].second) ++jumps;
    }
    cout << jumps+1;
}
