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
    stack<pair<int,int>> monotonic_stack;
    
    for(int i=1; i<=n; ++i){
        cin >> x;
        while(!monotonic_stack.empty()){
            if (monotonic_stack.top().first < x) {
                cout << monotonic_stack.top().second << " ";
                break;
            }
            monotonic_stack.pop(); 
        }

        if(monotonic_stack.empty()) cout << 0 << " ";
        monotonic_stack.push({x,i});
    }
}
