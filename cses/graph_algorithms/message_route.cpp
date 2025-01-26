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


// path 1->n shortest if exist 
void solution(){
    int n,m; cin >> n >> m; // nodes, edges
    vector<vector<int>> adj(n+1);
    vector<int> visited(n+1, 0); 
    vector<int> parent(n+1, -1); 
    vector<int> path;
    
    for(int i=1; i<=m; ++i){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // undirected graph
    }

    queue<int> q; 
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nextnode:adj[node]){
            if(!visited[nextnode]){
                visited[nextnode] = true;
                parent[nextnode] = node;
                q.push(nextnode);
            }
        }
    }

    if(!visited[n]) {cout << "IMPOSSIBLE\n"; return;}
    
    for(int node=n; node!= -1; node = parent[node]) path.push_back(node);

    cout << path.size() << "\n";
    for(int i=path.size()-1; i>=0; i--) cout << path[i] << " ";

}
