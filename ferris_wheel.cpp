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
    long n,x; cin >> n >> x;
    long weight[n]; 
    for(auto i=0; i<n; i++) cin >> weight[i];
    
    sort(weight, weight+n);
    long count=0, gweight=0, low=0, high=n-1;
    while(low<=high){
        count++;
        if(low==high) break;
        gweight = weight[high]; high--;
        if(gweight+weight[low] <= x) low++;
    }
    cout << count;
}
