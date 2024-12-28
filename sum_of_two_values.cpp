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
    long long n,x; cin >> n >> x;
    vector<pair<int,int>>a(n);
    for(auto i=0; i<n; ++i) {cin >> a[i].first; a[i].second=i+1;}

    sort(a.begin(), a.end());

    int i=0, j=n-1;
    while(i<j){
        if(a[i].first+a[j].first == x) {cout << a[i].second << " " << a[j].second; return;}
        if(a[i].first+a[j].first < x) ++i;
        else --j;
    }

    cout << "IMPOSSIBLE";
}
