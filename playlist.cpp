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
    for(int i=0; i<n; ++i) cin >> k[i];
 
    int ans=0;
    set<int> st;

    int start=0;
    for(int i=0; i<n; ++i){
        while(st.count(k[i])){
            st.erase(k[start]);
            start++;
        }
        st.insert(k[i]);
        ans = max(ans, int(st.size()));
    }
    cout << ans;
}
