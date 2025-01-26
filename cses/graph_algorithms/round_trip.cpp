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
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,0);
    vector<int> path;
    while(m--){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int startnode=0, endnode=0;

    // DFS - detect cycle (nested function)
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for(auto nextnode:adj[node]){
            if(!visited[nextnode]){
                parent[nextnode] = node;
                dfs(nextnode);
                if(startnode) return;
                else continue;
            }

            if(nextnode!=parent[node]){
                startnode = nextnode;
                endnode = node;
                return;
            }
        }
    };

    // handle disconnected components
    for(int node=1; node<=n; node++){
        if(visited[node]) continue;
        dfs(node);
        if(startnode) break;
    }

    if(!startnode) {cout << "IMPOSSIBLE"; return;}
    
    path.push_back(startnode);
    for(int node=endnode; node!=startnode; node=parent[node]){
        path.push_back(node);
    }
    path.push_back(startnode);
    cout << path.size() << "\n";
    for(auto node:path) cout << node << " ";
}
