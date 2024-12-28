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
    int n, count=0; cin >> n;
    vector<pair<int,int>> m(n); // movies(end,start)
    for(auto i=0; i<n; ++i) {
        cin >> m[i].second;
        cin >> m[i].first;
    }    
    sort(m.begin(), m.end()); // sort by movie-end-time
    int pend=0; // previous movie endtime
    for(int i=0; i<n;){
        while(i<n && m[i].second < pend) ++i;
        if(i==n) break;
        ++count;
        pend = m[i].first;
    }
    cout << count;
}
