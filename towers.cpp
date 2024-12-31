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
    int n,x; cin >> n;
    multiset<int> st; // learn: set WrongAnswer, multiset OK
    while(n--){
        cin >> x;
        auto it = st.upper_bound(x); // lowest(elem>x)
        if(it == st.end()) st.insert(x);
        else{
            st.erase(it);
            st.insert(x);
        }

        // for(auto x:st) cout << x << " ";
        // cout << "\n";
    }
    // cout << "ans-------\n";
    cout <<  st.size();
}
