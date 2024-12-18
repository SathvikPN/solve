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
    // code here
    string s; cin >> s;
    long long count=1, best=1;
    for(long long i=1; i<s.length(); i++) {
        if(s[i]==s[i-1]) count++;
        else {
            best = max(best, count);
            count = 1;
        }
    }
    cout << max(best, count);
}
