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
    long long n,t; cin >> n >> t; // machines, products as in description
    long long k[n];
    long long lowestTime = INFINITY;
    for(auto i=0; i<n; ++i){
        cin >> k[i];
        lowestTime = min(lowestTime, k[i]);
    }

    long long upperBoundTime = (lowestTime * t); // if only one machine worked without sharing load.
    long long lowerBoundTime = 1;
    long long ans = upperBoundTime;
    while(lowerBoundTime <= upperBoundTime){
        long long midTime = lowerBoundTime + ((upperBoundTime-lowerBoundTime)/2);
        long long productsMade=0;
        for(auto ki:k) {
            productsMade+=(midTime/ki);
            if(productsMade >= t) break;
        }
        if(productsMade < t) lowerBoundTime = midTime+1;
        else {
            ans = midTime; // valid answer so far, better might exist
            upperBoundTime = midTime-1;
        }
    }
    cout << ans;
}
