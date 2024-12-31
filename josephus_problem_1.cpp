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
    queue<int> q;
    for(int i=1; i<=n; ++i) q.push(i);

    int skipped=0; // every 2nd child removed == skip 1
    while(q.size()){
        int elem = q.front();
        q.pop();
        if(skipped) cout << elem << " ";
        else q.push(elem);
        skipped = (skipped+1)%2;  // rotates {0,1}
    }
}
