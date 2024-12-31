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
    int k[n];
    for(auto i=0; i<n; ++i) cin >> k[i];
 
    int start=0, maxCount=0; // starting idx of window
    set<int> currentSet; // learn: unordered_set TLE but set OK. 
    // frequent erases ------------------------------------------
    // set: balanced binary search tree, consistent O(logN) time complexity
    // unordered_set: hashtable, rehash if necessary, O(1) but sometimes O(N) hash-collisions
    
    for(int i=0; i<n; ++i){
        while(currentSet.count(k[i])){
            currentSet.erase(k[start]);
            start++;
        }
        currentSet.insert(k[i]);
        maxCount = max(maxCount, int(currentSet.size()));
    }
 
    cout << maxCount;
}
