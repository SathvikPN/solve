#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7; // 10^9 + 7
 
void solution();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

void solution(){
    string s; cin >> s;
    int length=1, longest=1;
    for(int i=1; i<s.size(); ++i){
        if(s[i]==s[i-1]) {length++; continue;}
        longest = max(longest, length);
        length = 1;
    }
    cout << max(longest, length);
}
