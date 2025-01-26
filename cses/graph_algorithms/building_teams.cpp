// cses: graph_algorithms 
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
    // graph coloring: 2 colors
    int n,m; cin >> n >> m; // nodes, edges
    vector<vector<int>> adj(n+1);
    vector<int> color(n+1, 0); // 1 || 2
    while(m--){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;

    // handle disconnected components 
    for(int startnode=1; startnode <=n; ++startnode){
        if(color[startnode]) continue;
        color[startnode] = 1;
        q.push(startnode);
        while(!q.empty()){
            int node = q.front(); q.pop();
            int nextcolor = 3 - color[node]; // 1+2-x {x=1==>2 x=2==>1}
            for(auto nextnode:adj[node]){
                if(color[nextnode] == color[node]) {cout << "IMPOSSIBLE\n"; return;}
                if(color[nextnode] == nextcolor) continue;
                color[nextnode] = nextcolor;
                q.push(nextnode);
            }
        }
    }
    for(int i=1; i<=n; ++i) cout << color[i] << " ";
}
