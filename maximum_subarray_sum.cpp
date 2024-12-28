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
    int x[n]; for(auto i=0; i<n; ++i) cin >> x[i];
    
    long long csum=x[0], bsum=x[0]; // current_sum, best_sum
    for(auto i=1; i<n; ++i){
        if(csum+x[i] > x[i]) csum+=x[i];
        else csum=x[i];
        bsum = max(bsum, csum);
    }
    cout << bsum;
}
