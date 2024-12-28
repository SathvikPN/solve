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
    long long n; cin >> n;
    long long a[n], b[n];
    for(auto i=0; i<n; ++i) {cin >> a[i]; cin >> b[i];}

    sort(a, a+n);
    sort(b, b+n);

    long long count=0, maxCount=0;
    for(long long i=0,j=0; i<n && j<n;){
        if(a[i]==b[j]) {++i; ++j; continue;}
        if(a[i]<b[j]) {count++; maxCount=max(maxCount, count); ++i;}
        else {count--; ++j; }
    }
    cout << maxCount;
}
