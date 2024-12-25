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
    long long n,m,k; cin >> n >> m >> k;
    long long a[n], b[m];
    long long i=0, j=0, count=0;
    for(auto i=0; i<n; i++) cin >> a[i]; // applicants bidding
    for(auto j=0; j<m; j++) cin >> b[j]; // buildings available

    sort(a, a+n); 
    sort(b, b+m);

    while(i<n && j<m){
        if((a[i]+k) < b[j]) {i++; continue;}
        if((a[i]-k) > b[j]) {j++; continue;}
        i++; j++;
        count++;
    }
    
    cout << count;
}
