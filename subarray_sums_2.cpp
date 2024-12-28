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
    int n,x; cin >> n >> x;
    int a[n];
    for(auto i=0; i<n; ++i) cin >> a[i];

    long long csum=0, count=0;
    map<long long,long long> seen; // seen[csum]=count
    seen[0]++;

    for(auto i=0; i<n; ++i){
        csum = csum + a[i];
        count = count + seen[csum-x];
        seen[csum]++;
    }
    cout << count;
}
