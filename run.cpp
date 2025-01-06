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
    string s = "hi";
    // cout << s.size() << s.length() << s[3];
    vector<char>a(5, 'x');
    for(int i=0; i<=s.size(); i++) a[i]=s[i];
    for(auto c:a)  cout << "[" << c << "]";
}
