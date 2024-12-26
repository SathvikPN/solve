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
    int count=0, csum=0, left=0;
    int a[n];
    for(int i=0; i<n; ++i){
        cin >> a[i];
        csum = csum + a[i];
        while(left<=i && csum > x) csum = csum-a[left++];
        if(csum==x) count++;
    }
    cout << count;
}
